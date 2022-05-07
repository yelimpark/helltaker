#include "StageScene.h"
#include <SFML/Graphics.hpp>
#include "../Framework/Framework.h"

#include "../Utils/rapidcsv.h"
#include "../Utils/InputManager.h"
#include "../Utils/Utils.h"

#include "../UI/StageUI.h"
#include "../GameObj/Flame.h"
#include "../GameObj/Box.h"
#include "../GameObj/MapCode.h"

#include <sstream>

using namespace sf;

StageScene::StageScene(SceneManager& sceneManager)
	: Scene(sceneManager), level(GameVal::level), isClear(false)
{

}

void StageScene::InitMap(std::string filepath, std::string levelStr)
{
	std::map<std::string, std::vector<BoxData>> boxDatas;
	Utils::CsvToStructVectorMap<BoxData>(boxDatas, "./LevelInfo/BoxInfo.csv");
	int boxIdx = 0;

	Vector2f playerPos;
	Vector2f DemonPos;

	rapidcsv::Document csvData(filepath);

	int row = resolution.y / TILE_SIZE;
	int col = resolution.x / TILE_SIZE;

	map = new char* [row];
	for (int i = 0; i < row; ++i) {
		map[i] = new char[col];
		for (int j = 0; j < col; ++j) {
			map[i][j] = csvData.GetCell<char>(j + 1, i + 1);

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

			default:
				break;
			}
		}
	}

	player.Init(playerPos, TILE_SIZE, MOVE_SECOND);
	demon.Init(DemonPos);

	for (auto& boxdata : boxDatas[levelStr])
	{
		Box* box = new Box();
		box->Init(boxdata, TILE_SIZE, MOVE_SECOND);
		boxes.push_back(box);
	}
}

void StageScene::Init()
{
	std::map<std::string, LevelData> levelDatas;
	std::map<std::string, std::vector<FlameData>> flameDatas;
	std::map<std::string, std::vector<FlameBaseData>> flameBaseDatas;

	Utils::CsvToStruct<LevelData>(levelDatas, "./LevelInfo/LevelInfo.csv");
	Utils::CsvToStructVectorMap<FlameData>(flameDatas, "./LevelInfo/FlameInfo.csv");
	Utils::CsvToStructVectorMap<FlameBaseData>(flameBaseDatas, "./LevelInfo/FlameBaseInfo.csv");

	stringstream ss;
	ss << level;
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
	sideLeft.setPosition(0, 0);
	sideRight.setPosition(resolution.x, 0);
	sideRight.setScale(-1.f, 1.f);

	ui.Init(levelData.lastTurn);
	transition.Init(resolution);

	isClear = false;
}

void StageScene::Update(Time& dt)
{
	for (auto flame : flames) {
		flame->Update(dt.asSeconds());
	}

	for (auto& box : boxes)
	{
		box->Update(dt.asSeconds());
	}

	player.Update(dt.asSeconds());
	if (!isClear && player.HanddleInput(map, boxes)) {
		ui.UseTurn();
	}
	
	demon.Update(dt.asSeconds());
	isClear = demon.IsClear(map, TILE_SIZE);

	if (isClear) {
		transition.Update(dt.asSeconds());
		ui.OnClear(dt.asSeconds());
	}
}

void StageScene::Render()
{
	window.setView(mainView);
	window.draw(Background);
	window.draw(sideLeft);
	window.draw(sideRight);

	for (auto flamebase : flameBases) {
		window.draw(*flamebase);
	}

	for (auto flame : flames) {
		flame->Draw(window);
	}

	for (auto& box : boxes)
	{
		box->Draw(window);
	}

	player.Draw(window);
	demon.Draw(window);
	transition.Draw(window);
	ui.Draw(window);
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
}

StageScene::~StageScene()
{
	Release();
}

int StageScene::GetTileSize()
{
	return TILE_SIZE;
}
