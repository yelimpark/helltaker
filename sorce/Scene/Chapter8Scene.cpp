#include "Chapter8Scene.h"
#include "../Utils/rapidcsv.h"
#include "../Utils/Utils.h"
#include "../Utils/InputManager.h"

#include "../Framework/Framework.h"
#include "../Resource/TextureHolder.h"

#include "../GameObj/Flame.h"
#include "../GameObj/MapCode.h"
#include "../GameObj/Skull.h"

Chapter8Scene::Chapter8Scene(SceneManager& sceneManager)
	:Scene(sceneManager),
	playerView(Framework::GetPlayerView()), pmenu(window, sceneManager), isClear(false)
{

}

void Chapter8Scene::Init()
{
	Release();

	std::map<std::string, LevelData> levelDatas;
	std::map<std::string, std::vector<FlameData>> flameDatas;
	std::map<std::string, std::vector<FlameBaseData>> flameBaseDatas;

	Utils::CsvToStruct<LevelData>(levelDatas, "./LevelInfo/LevelInfo.csv");
	Utils::CsvToStructVectorMap<FlameData>(flameDatas, "./LevelInfo/FlameInfo.csv");
	Utils::CsvToStructVectorMap<FlameBaseData>(flameBaseDatas, "./LevelInfo/FlameBaseInfo.csv");
	LevelData levelData = levelDatas[to_string(8)];

	InitMap(levelData.MapFilePath);

	//for (int i = 0; i < 8; ++i) {
	//	Flame* flame = new Flame();
	//	flame->Init(flameDatas[to_string(GameVal::level)][i].position);
	//	flames.push_back(flame);
	//}

	//for (int i = 0; i < 8; ++i) {
	//	Sprite* flameBase = new Sprite();
	//	flameBase->setTexture(TextureHolder::GetTexture("Sprite/FLAMEbase0001.png"));
	//	flameBase->setPosition(flameBaseDatas[to_string(GameVal::level)][i].position);
	//	flameBases.push_back(flameBase);
	//}

	background.setTexture(TextureHolder::GetTexture("Sprite/chapterSketches_EXPORT_throne.png"));
	sideLeft.setTexture(TextureHolder::GetTexture("Sprite/mainUIexport_bUI2.png"));
	sideRight.setTexture(TextureHolder::GetTexture("Sprite/mainUIexport_bUI2.png"));

	Utils::SetOrigin(sideLeft, Pivots::LeftTop);
	Utils::SetOrigin(sideRight, Pivots::LeftTop);
	sideLeft.setPosition(0, 0);
	sideRight.setPosition(resolution.x, 0);
	sideRight.setScale(-1.f, 1.f);


	paused = false;
	isClear = false;
}

void Chapter8Scene::InitMap(std::string filepath)
{
	Vector2f playerPos;

	rapidcsv::Document csvData(filepath, rapidcsv::LabelParams(-1, -1));
	map = new char* [csvData.GetRowCount()];

	for (int i = 0; i < csvData.GetRowCount(); ++i) {
		map[i] = new char[csvData.GetColumnCount()];

		for (int j = 0; j < csvData.GetColumnCount(); ++j) {
			map[i][j] = csvData.GetCell<char>(j, i);
			std::cout << map[i][j];

			switch (map[i][j]) {
			case (char)MapCode::BOX:
				break;

			case (char)MapCode::PLAYER:
				playerPos = Utils::IdxToPos(i, j);
				break;

			case (char)MapCode::LOCKEDBOX:
				break;

			case (char)MapCode::CLAW:
				break;

			case (char)MapCode::SKULL:
			{
				Skull* skull = new Skull();
				skull->Init(Utils::IdxToPos(i, j), TILE_SIZE, MOVE_SECOND);
				skulls.push_back(skull);
				break;
			}
			}

			player.Init(playerPos, TILE_SIZE, MOVE_SECOND);
		}
	}

}

void Chapter8Scene::Update(Time& dt)
{
	UpdatePauseInput(dt);
	if (paused) {
		pmenu.Update();
		return;
	}

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

	boneParticle.Update(dt.asSeconds());

	if (isClear) {
		ui.OnClear(dt.asSeconds());
		if (stageTransition.OnClear(dt.asSeconds())) {
			GameVal::cutSceneIdx = 8;
			sceneManager.ChangeScene(SceneType::CUT);
			GameVal::level = 9;
		}
	}
	//else {
	//	if (ui.IsGameOver()) {
	//		if (gameOver.OnGameOver(dt.asSeconds(), player.GetPos())) {
	//			sceneManager.ChangeScene(SceneType::STAGE8, true);
	//		}
	//		return;
	//	}
	//}

	if (InputManager::GetKeyDown(Keyboard::R))
	{
		sceneManager.ChangeScene(SceneType::STAGE8, true);
	}
}

void Chapter8Scene::PausedState()
{
	paused = true;
	pmenu.UpInit();
}

void Chapter8Scene::UnPausedState()
{
	paused = false;
}

void Chapter8Scene::UpdatePauseInput(Time& dt)
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


void Chapter8Scene::Render()
{
	window.setView(playerView);
	window.draw(background);

	for (auto& skull : skulls)
	{
		skull->Draw(window);
	}

	player.Draw(window);


	window.setView(mainView);
	
	window.draw(sideLeft);
	window.draw(sideRight);
	ui.Draw(window);
	
	//if (!isClear && ui.IsGameOver()) {
	//	gameOver.Draw(window);
	//}

	if (paused)
	{
		pmenu.Render(window);
	}
}

void Chapter8Scene::Release()
{
	//for (auto flame : flames) {
	//	if (flame != nullptr)
	//		delete flame;
	//}
	//flames.clear();

	//for (auto flamebase : flameBases) {
	//	if (flamebase != nullptr)
	//		delete flamebase;
	//}
	//flameBases.clear();

	for (auto& skull : skulls)
	{
		if (skull != nullptr)
			delete skull;
	}
	skulls.clear();
}

Chapter8Scene::~Chapter8Scene()
{
	Release();
}
