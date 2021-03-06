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
#include "../GameObj/Demon.h"
#include "../GameObj/Key.h"
#include "../GameObj/LockedBox.h"

#include <algorithm>
#include<string>

StageScene::StageScene(SceneManager& sceneManager)
	: Scene(sceneManager), isClear(false), pmenu(window, sceneManager), 
	key(nullptr), lockedBox(nullptr)
{

}

void StageScene::InitMap(std::string filepath, std::string clawFilePath, std::string demonName)
{
	std::string levelStr = to_string(GameVal::level);


	std::map<std::string, std::vector<BoxData>> boxDatas;
	Utils::CsvToStructVectorMap<BoxData>(boxDatas, "./LevelInfo/BoxInfo.csv");
	int boxIdx = 0;

	Vector2f playerPos;
	Vector2f KeyPos;
	Vector2f LockedBoxPos;

	rapidcsv::Document csvData(filepath, rapidcsv::LabelParams(-1, -1));
	rapidcsv::Document csvDataC(clawFilePath, rapidcsv::LabelParams(-1, -1));

	map = new char* [csvData.GetRowCount()];

	for (int i = 0; i < csvData.GetRowCount(); ++i) {
		map[i] = new char[csvData.GetColumnCount() - 1];

		for (int j = 0; j < csvData.GetColumnCount() - 1; ++j) {
			map[i][j] = csvData.GetCell<char>(j, i);

			switch (map[i][j]) {
			case (char)MapCode::BOX:
				boxDatas[levelStr][boxIdx].position = Utils::IdxToPos(i, j);
				boxIdx++;
				break;

			case (char)MapCode::PLAYER:
				playerPos = Utils::IdxToPos(i, j);
				break;

			case (char)MapCode::DEMON:
			{
				Demon* demon = new Demon();
				demon->Init(Utils::IdxToPos(i, j), demonName);
				demons.push_back(demon);
				break;
			}

			case (char)MapCode::SKULL: 
			{
				Skull* skull = new Skull();
				skull->Init(Utils::IdxToPos(i, j), TILE_SIZE, MOVE_SECOND);
				skulls.push_back(skull);
				break;
			}

			case (char)MapCode::KEY:
			{
				KeyPos = Utils::IdxToPos(i, j);
				key->Init(KeyPos);
				break;
			}

			case (char)MapCode::LOCKEDBOX:
			{
				LockedBoxPos = Utils::IdxToPos(i, j);
				lockedBox->Init(LockedBoxPos);
				break;
			}

			default:
				break;
			}

			switch (csvDataC.GetCell<char>(j, i)) {
			case (char)MapCode::CLAW:
			{
				Claw* claw = new Claw();
				claw->Init(Utils::IdxToPos(i, j));
				claws.push_back(claw);
				break;
			}

			default:
				break;
			}

		}
	}

	player.Init(playerPos, TILE_SIZE, MOVE_SECOND);

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

	std::map<std::string, LevelData> levelDatas;
	std::map<std::string, std::vector<FlameData>> flameDatas;
	std::map<std::string, std::vector<FlameBaseData>> flameBaseDatas;

	Utils::CsvToStruct<LevelData>(levelDatas, "./LevelInfo/LevelInfo.csv");
	Utils::CsvToStructVectorMap<FlameData>(flameDatas, "./LevelInfo/FlameInfo.csv");
	Utils::CsvToStructVectorMap<FlameBaseData>(flameBaseDatas, "./LevelInfo/FlameBaseInfo.csv");

	LevelData levelData = levelDatas[to_string(GameVal::level)];
	
	if (GameVal::level == 8)
	{
		sceneManager.ChangeScene(SceneType::STAGE8, true);
	}

	key = new Key();
	lockedBox = new LockedBox();

	InitMap(levelData.MapFilePath, levelData.ClawMapFilePath, levelData.demonName);

	for (int i = 0; i < flameDatas[to_string(GameVal::level)].size(); ++i) {
		Flame* flame = new Flame();
		flame->Init(flameDatas[to_string(GameVal::level)][i].position);
		flames.push_back(flame);
	}

	for (int i = 0; i < flameBaseDatas[to_string(GameVal::level)].size(); ++i) {
		Sprite * flameBase = new Sprite();
		flameBase->setTexture(TextureHolder::GetTexture(flameBaseDatas[to_string(GameVal::level)][i].texturefile));
		flameBase->setPosition(flameBaseDatas[to_string(GameVal::level)][i].position);
		flameBases.push_back(flameBase);
	}

	Background.setTexture(TextureHolder::GetTexture(levelData.BgFilename));
	Background.setPosition(levelData.bgPos);

	sideLeft.setTexture(TextureHolder::GetTexture("Sprite/mainUIexport_bUI2.png"));
	sideRight.setTexture(TextureHolder::GetTexture("Sprite/mainUIexport_bUI2.png"));
	Utils::SetOrigin(sideLeft, Pivots::LeftTop);
	Utils::SetOrigin(sideRight, Pivots::LeftTop);
	sideLeft.setPosition(0, 0);
	sideRight.setPosition(resolution.x, 0);
	sideRight.setScale(-1.f, 1.f);

	ui.Init(levelData.lastTurn, resolution);
	stageTransition.Init(resolution);
	gameOver.Init(resolution);

	isClear = false;
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

	if (paused) {
		pmenu.Update();
		return;
	}

	for (auto flame : flames) {
		flame->Update(dt.asSeconds());
	}

	for (auto& box : boxes)
	{
		box->Update(dt.asSeconds());
	}

	key->Update(dt.asSeconds(), player.GetPos(), TILE_SIZE);

	bool isOpen = key->IsCapturedPlayer();
	lockedBox->Update(dt.asSeconds(), isOpen, player.GetPos(), TILE_SIZE);

	player.Update(dt.asSeconds());

	if (!isClear && !ui.IsGameOver()) {
		if (player.HanddleInput(map, boxes, skulls, *lockedBox))
			ui.UseTurn();
	}

	for (int i = 0; i < skulls.size(); i++) {
		skulls[i]->Update(dt.asSeconds());
		if (skulls[i]->IsDead()) {
			boneParticle.Init(skulls[i]->GetPos());
			map[(int)skulls[i]->GetPos().y / TILE_SIZE][(int)skulls[i]->GetPos().x / TILE_SIZE] = 'E';
			delete skulls[i];
			skulls.erase(skulls.begin() + i);
		}
	}

	for (auto& claw : claws) {
		if (claw->Update(dt.asSeconds(), skulls, player)) {
			bloodVfx.Init(player.GetPos());
			ui.UseTurn();
		}
	}

	boneParticle.Update(dt.asSeconds());
	bloodVfx.Update(dt.asSeconds());

	for (auto& demon : demons) {
		demon->Update(dt.asSeconds());
		if (demon->IsClear(map, TILE_SIZE)) isClear = true;
	}

	if (isClear) {
		ui.OnClear(dt.asSeconds());
		if (stageTransition.OnClear(dt.asSeconds())) {
			GameVal::cutSceneIdx = GameVal::level;
			sceneManager.ChangeScene(SceneType::CUT);
		}
	}
	else {
		if (ui.IsGameOver()) {
			if (gameOver.OnGameOver(dt.asSeconds(), player.GetPos())) {
				sceneManager.ChangeScene(SceneType::STAGE, true);
			}
			return;
		}
	}

	if (InputManager::GetKeyDown(Keyboard::R))
	{
		sceneManager.ChangeScene(SceneType::STAGE, true);
	}

}

void StageScene::Render()
{
	window.setView(mainView);
	window.draw(Background);
	window.draw(sideLeft);
	window.draw(sideRight);
	key->Draw(window);
	lockedBox->Draw(window);

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

	for (auto& demon : demons)
	{
		demon->Draw(window);
	}

	player.Draw(window);
	boneParticle.Draw(window);
	bloodVfx.Draw(window);
	stageTransition.Draw(window);
	ui.Draw(window);

	if (!isClear && ui.IsGameOver()) {
		gameOver.Draw(window);
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

	for (auto& demon : demons)
	{
		if (demon != nullptr)
			delete demon;
	}
	demons.clear();

	for (auto& claw : claws)
	{
		if (claw != nullptr)
			delete claw;
	}
	claws.clear();

	delete key;
	key = nullptr;
	delete lockedBox;
	lockedBox = nullptr;
}

StageScene::~StageScene()
{
	Release();
}

int StageScene::GetTileSize()
{
	return TILE_SIZE;
}
