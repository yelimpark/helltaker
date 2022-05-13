#include "StageScene.h"
#include <SFML/Graphics.hpp>

#include "../Resource/TextureHolder.h"
#include "../Utils/rapidcsv.h"
#include "../Utils/InputManager.h"
#include "../Utils/Utils.h"
#include "../Resource/FontHolder.h"

#include "../UI/StageUI.h"
#include "../GameObj/Flame.h"
#include "../GameObj/Box.h"
#include "../GameObj/Skull.h"
#include "../GameObj/MapCode.h"
#include "../GameObj/Claw.h"

#include <sstream>
#include <algorithm>

StageScene::StageScene(SceneManager& sceneManager)
	: Scene(sceneManager), level(GameVal::level), isClear(false), isEarnedKey(false), isEarnedBox(false), pmenu(window, sceneManager)
{

}

void StageScene::InitMap(std::string filepath, std::string levelStr)
{
	std::map<std::string, std::vector<BoxData>> boxDatas;
	Utils::CsvToStructVectorMap<BoxData>(boxDatas, "./LevelInfo/BoxInfo.csv");
	int boxIdx = 0;

	Vector2f playerPos;
	Vector2f DemonPos;
	Vector2f KeyPos;
	Vector2f LockedBoxPos;

	rapidcsv::Document csvData(filepath, rapidcsv::LabelParams(-1, -1));

	int row = resolution.y / TILE_SIZE;
	int col = resolution.x / TILE_SIZE;

	map = new char* [row];
	for (int i = 0; i < row; ++i) {
		map[i] = new char[col];
		for (int j = 0; j < col; ++j) {
			map[i][j] = csvData.GetCell<char>(j, i);

			switch (map[i][j]) {
			case (char)MapCode::BOX:
				boxDatas[levelStr][boxIdx].position.x = j * TILE_SIZE + LEFT_MARGINE;
				boxDatas[levelStr][boxIdx].position.y = i * TILE_SIZE + TOP_MARGINE;
				boxIdx++;
				break;

			case (char)MapCode::PLAYER:
				playerPos.x = j * TILE_SIZE + TILE_SIZE / 2 + LEFT_MARGINE;
				playerPos.y = i * TILE_SIZE + TILE_SIZE / 2 + TOP_MARGINE;
				break;

			case (char)MapCode::DEMON:
				DemonPos.x = j * TILE_SIZE + TILE_SIZE / 2 + LEFT_MARGINE;
				DemonPos.y = i * TILE_SIZE + TILE_SIZE / 2 + TOP_MARGINE;
				break;

			case (char)MapCode::SKULL: 
			{
				Vector2f pos;
				pos.x = j * TILE_SIZE + TILE_SIZE / 2 + LEFT_MARGINE;
				pos.y = i * TILE_SIZE + TILE_SIZE / 2 + TOP_MARGINE;
				Skull* skull = new Skull();
				skull->Init(pos, TILE_SIZE, MOVE_SECOND);
				skulls.push_back(skull);
				break;
			}

			case (char)MapCode::CLAW:
			{
				Vector2f pos;
				pos.x = j * TILE_SIZE + TILE_SIZE / 2 + LEFT_MARGINE;
				pos.y = i * TILE_SIZE + TILE_SIZE / 2 + TOP_MARGINE;
				Claw* claw = new Claw();
				claw->Init(pos, TILE_SIZE);
				claws.push_back(claw);
				break;
			}

			case (char)MapCode::KEY:
			{
				KeyPos.x = j * TILE_SIZE + TILE_SIZE / 2 + LEFT_MARGINE;
				KeyPos.y = i * TILE_SIZE + TILE_SIZE / 2 + TOP_MARGINE;
				break;
			}

			case (char)MapCode::LOCKEDBOX:
			{
				LockedBoxPos.x = j * TILE_SIZE + TILE_SIZE / 2 + LEFT_MARGINE;
				LockedBoxPos.y = i * TILE_SIZE + TILE_SIZE / 2 + TOP_MARGINE;
				break;
			}

			default:
				break;
			}

		}
	}

	player.Init(playerPos, TILE_SIZE, MOVE_SECOND);
	demon.Init(DemonPos);
	key.Init(KeyPos, TILE_SIZE);
	lockedBox.Init(LockedBoxPos);

	for (auto& boxdata : boxDatas[levelStr])
	{
		Box* box = new Box();
		box->Init(boxdata, TILE_SIZE, MOVE_SECOND);
		boxes.push_back(box);
	}
}

void StageScene::Init()
{
	Release();
	paused = false;

	soundEffects.backgroundMusic();
	std::map<std::string, LevelData> levelDatas;
	std::map<std::string, std::vector<FlameData>> flameDatas;
	std::map<std::string, std::vector<FlameBaseData>> flameBaseDatas;

	Utils::CsvToStruct<LevelData>(levelDatas, "./LevelInfo/LevelInfo.csv");
	Utils::CsvToStructVectorMap<FlameData>(flameDatas, "./LevelInfo/FlameInfo.csv");
	Utils::CsvToStructVectorMap<FlameBaseData>(flameBaseDatas, "./LevelInfo/FlameBaseInfo.csv");

	stringstream ss;
	ss << GameVal::level;
	LevelData levelData = levelDatas[ss.str()];

	InitMap(levelData.MapFilePath, ss.str());

	for (int i = 0; i < flameDatas[ss.str()].size(); ++i) {
		Flame* flame = new Flame();
		flame->Init(flameDatas[ss.str()][i].position);
		flames.push_back(flame);
	}

	for (int i = 0; i < flameBaseDatas[ss.str()].size(); ++i) {
		Sprite * flameBase = new Sprite();
		flameBase->setTexture(TextureHolder::GetTexture(flameBaseDatas[ss.str()][i].texturefile));
		flameBase->setPosition(flameBaseDatas[ss.str()][i].position);
		flameBases.push_back(flameBase);
	}

	Background.setTexture(TextureHolder::GetTexture(levelData.BgFilename));
	Background.setPosition(levelData.bgPos);

	sideLeft.setTexture(TextureHolder::GetTexture("Sprite/mainUIexport_bUI2.png"));
	sideRight.setTexture(TextureHolder::GetTexture("Sprite/mainUIexport_bUI2.png"));
	sideLeft.setPosition(resolution.x*0.03f, 0);
	sideRight.setPosition(resolution.x*0.97f, 0);
	sideRight.setScale(-1.f, 1.f);

	text.setFont(FontHolder::GetFont("Font/CrimsonPro-Bold.ttf"));
	text.setCharacterSize(35);
	text.setStyle(Text::Bold);
	text.setString("LIFE ADVICE [L or LB]               RESTART [R or RB]");
	Utils::SetOrigin(text, Pivots::Center);
	text.setPosition(Vector2f(resolution.x * 0.5f, resolution.y * 0.95f));


	ui.Init(levelData.lastTurn);
	stageTransition.Init(resolution);
	if (!cutTransition.IsFull())
		cutTransition.Init();

	gameOver.Init(resolution);

	isClear = false;
	isEarnedKey = false;
	isEarnedBox = false;
}

void StageScene::PausedState()
{
	paused = true;
	pmenu.UpInit();

}

void StageScene::UnPausedState()
{
	paused = false;
}

void StageScene::UpdatePauseInput(Time& dt)
{
	if (InputManager::GetKeyDown(Keyboard::Escape))
	{
		if (!paused)
		{
			PausedState();
		}
		else
		{
			UnPausedState();
		}
	}
}

void StageScene::Update(Time& dt)
{
	UpdatePauseInput(dt);
	
	if (!paused) //Unpaused update
	{

		for (auto flame : flames) {
			flame->Update(dt.asSeconds());
		}

		for (auto& box : boxes)
		{
			box->Update(dt.asSeconds());
		}

		player.Update(dt.asSeconds());
		if (!isClear && !ui.IsGameOver()) {
			if (player.HanddleInput(map, boxes, skulls, lockedBox, isEarnedKey, dt.asSeconds()))
				ui.UseTurn();
		}

		for (int i = 0; i < skulls.size(); i++) {
			skulls[i]->Update(dt.asSeconds());
			if (skulls[i]->IsDead()) {
				boneParticle.Init(skulls[i]->GetPos());
				soundEffects.crushSkull();
				map[(int)skulls[i]->GetPos().y / TILE_SIZE][(int)skulls[i]->GetPos().x / TILE_SIZE] = 'E';
				delete skulls[i];
				skulls.erase(skulls.begin() + i);
			}
		}

		for (int i = 0; i < claws.size(); i++)
		{
			claws[i]->Update(dt.asSeconds() * 5);
			claws[i]->IsActive();
			for (auto skull : skulls)
			{
				if (!skull->IsMoving() && claws[i]->IsActive() && claws[i]->IsSkullIn(map, TILE_SIZE, skull))
				{
					skulls[i]->IsDead();
					soundEffects.crushSkull();
					boneParticle.Init(skulls[i]->GetPos());
					map[(int)skulls[i]->GetPos().y / TILE_SIZE][(int)skulls[i]->GetPos().x / TILE_SIZE] = 'E';
					delete skulls[i];
					skulls.erase(skulls.begin() + i);
				}
			}

			if (claws[i]->IsActive() && claws[i]->IsPlayerIn(map, TILE_SIZE))
			{
				soundEffects.PlayerInClaw();
				bloodVfx.Init(player.GetPos());

				//ui.UseTurn();
			}
		}

		boneParticle.Update(dt.asSeconds());
		bloodVfx.Update(dt.asSeconds());

		demon.Update(dt.asSeconds());
		isClear = demon.IsClear(map, TILE_SIZE);

		if (!isClear && ui.IsGameOver()) {
			if (gameOver.OnGameOver(dt.asSeconds(), player.GetPos())) {
				cutTransition.Update(dt.asSeconds());
				if (cutTransition.IsFull()) {
					Init();

				}
			}
			return;
		}

		if (isClear) {
			ui.OnClear(dt.asSeconds());
			if (stageTransition.OnClear(dt.asSeconds())) {
				sceneManager.ChangeScene(SceneType::LEVELENDING);
			}
		}

		isEarnedKey = key.IsCapturedPlayer(map, TILE_SIZE);
		if (isEarnedKey)
		{
			key.Clear();
			soundEffects.getKey();
		}
		key.Update(dt.asSeconds());

		isEarnedBox = lockedBox.IsCapturedPlayer(map, TILE_SIZE);
		if (isEarnedBox)
		{
			lockedBox.Clear();
		}
		lockedBox.Update(dt.asSeconds());

		if (InputManager::GetKeyDown(Keyboard::R))
		{
			cutTransition.Init();
			Init();
		}
	}

	else //paused update
	{
		pmenu.Update();
	}

}

void StageScene::Render()
{
	window.setView(mainView);
	window.draw(Background);
	window.draw(sideLeft);
	window.draw(sideRight);
	key.Draw(window);
	lockedBox.Draw(window);

	for (auto flamebase : flameBases) {
		window.draw(*flamebase);
	}

	for (auto flame : flames) {
		flame->Draw(window);
	}

	for (auto& claw : claws)
	{
		claw->Draw(window);
	}
	
	for (auto& box : boxes)
	{
		box->Draw(window);
	}

	for (auto& skull : skulls)
	{
		skull->Draw(window);
	}

	player.Draw(window);
	demon.Draw(window);
	boneParticle.Draw(window);
	bloodVfx.Draw(window);

	stageTransition.Draw(window);
	window.draw(text);
	ui.Draw(window);

	if (!isClear && ui.IsGameOver()) {
		if (!cutTransition.IsFull())
			gameOver.Draw(window);
		cutTransition.Draw(window);
	}

	if (paused) //paused menu render
	{
		pmenu.Render(window);
	}
}

void StageScene::Release()
{
	for (auto flame : flames) {
		if (flame != nullptr)
			delete flame;
	}
	flames.clear();

	for (auto flamebase : flameBases) {
		if (flamebase != nullptr)
			delete flamebase;
	}
	flameBases.clear();

	for (auto& box : boxes)
	{
		if (box != nullptr)
			delete box;
	}
	boxes.clear();

	for (auto& skull : skulls)
	{
		if (skull != nullptr)
			delete skull;
	}
	skulls.clear();
}

StageScene::~StageScene()
{
	Release();
}

int StageScene::GetTileSize()
{
	return TILE_SIZE;
}
