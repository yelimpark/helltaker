#include "StageScene.h"
#include <SFML/Graphics.hpp>
#include "../Framework/Framework.h"

#include "../UI/StageUI.h"
#include "../Utils/rapidcsv.h"
#include "../Utils/InputManager.h"
#include "../Utils/Utils.h"

#include "../GameObj/Flame.h"
#include "../GameObj/Box.h"

#include <sstream>

using namespace sf;

void StageScene::InitMap(std::string filepath, std::string levelStr)
{
	std::map<std::string, std::vector<BoxData>> boxDatas;
	Utils::CsvToStructVectorMap<BoxData>(boxDatas, "./LevelInfo/BoxInfo.csv");
	int boxIdx = 0;

	Vector2f playerPos;

	rapidcsv::Document csvData(filepath);

	int row = resolution.y / TILE_SIZE;
	int col = resolution.x / TILE_SIZE;

	map = new char*[row];
	for (int i = 0; i < row; ++i) {
		map[i] = new char[col];
		for (int j = 0; j < col; ++j) {
			map[i][j] = csvData.GetCell<char>(j+1, i+1);

			switch (map[i][j]) {
			case 'B':
				boxDatas[levelStr][boxIdx].position.x = j * 100 + LEFT_MARGINE;
				boxDatas[levelStr][boxIdx].position.y = i * 100 + TOP_MARGINE;
				boxIdx++;
				break;

			case 'P':
				playerPos.x = j * 100 + TILE_SIZE / 2 + LEFT_MARGINE;
				playerPos.y = i * 100 + TILE_SIZE / 2 + TOP_MARGINE;
				break;

			default:
				break;
			}
		}
	}

	player.Init(playerPos, TILE_SIZE);

	for (auto& boxdata : boxDatas[levelStr])
	{
		Box* box = new Box();
		box->Init(boxdata, TILE_SIZE);
		boxes.push_back(box);
	}
}

StageScene::StageScene(SceneManager& sceneManager)
	: Scene(sceneManager), lastTurn(0), level(GameVal::level), transHeight(0), opacity(0), transeScene(false)
{

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

	lastTurn = levelData.lastTurn;

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
	spriteSide1.setTexture(TextureHolder::GetTexture("Sprite/mainUIexport_bUI2.png"));
	spriteSide2.setTexture(TextureHolder::GetTexture("Sprite/mainUIexport_bUI2.png"));
	transition.setTexture(TextureHolder::GetTexture("Sprite/dialogueBG_hell.png"));
	FloatRect transRect = transition.getLocalBounds();
	transition.setOrigin(transRect.left+transRect.width*0.5, transRect.top + transRect.height * 0.5f);
	transBack.setSize(Vector2f(resolution.x, resolution.y));
	transBack.setFillColor(Color::Transparent);

	Background.setPosition(levelData.bgPos);
	spriteSide1.setPosition(0, 0);
	spriteSide2.setPosition(resolution.x, 0);
	spriteSide2.setScale(-1.f, 1.f);

	ui.Init();

	demon.Init(1260, 766);

	transeScene = false;
	StageUI::isMovedSide = false;
}

void StageScene::Update(Time& dt)
{
	for (auto flame : flames) {
		flame->Update(dt.asSeconds());
	}

	for (auto& boxesInfo : boxes)
	{
		boxesInfo->Update(dt.asSeconds());
	}
	player.Update(dt.asSeconds());
	player.HanddleInput(map);
	demon.Update(dt.asSeconds());

	ui.Update(lastTurn);

	if (InputManager::GetKeyDown(Keyboard::Enter))
	{
		transeScene = true;
	}

	if (transeScene)
	{
		ui.MoveSide(dt.asMilliseconds());
		TranseScene(dt.asMilliseconds());
	}
	//csv 파일로 끌어와서 작업 할 수 있도록!!!
}

void StageScene::Render()
{
	window.setView(mainView);
	window.draw(Background);
	window.draw(spriteSide1);
	window.draw(spriteSide2);

	for (auto flamebase : flameBases) {
		window.draw(*flamebase);
	}

	for (auto flame : flames) {
		flame->Draw(window);
	}

	for (auto& boxesInfo : boxes)
	{
		boxesInfo->Draw(window);
	}

	player.Draw(window);
	demon.Draw(window);

	if (transeScene)
	{
		window.draw(transBack);
		window.draw(transition);
	}
	ui.Render(window);
	
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
}

void StageScene::TranseScene(float dt)
{
	transBack.setFillColor(Color{ 0, 0, 0, (Uint8)opacity });
	transition.setTextureRect( { 0, (int)((544.f-transHeight)*0.5f), resolution.x, (int)transHeight});
	FloatRect transRect = transition.getLocalBounds();
	transition.setOrigin((transRect.left + transRect.width) * 0.5, (transRect.top + transRect.height) * 0.5f);
	transition.setPosition(resolution.x * 0.5f, resolution.y * 0.4f);


	if (transHeight >= 544)
	{
		transBack.setFillColor(Color::Black);
		sceneManager.ChangeScene(SceneType::TITLE);
	}
	else
	{
		if (opacity < 255)
		{
			opacity += dt;
		}
		else
		{
			transBack.setFillColor(Color::Black);
		}

		transHeight += dt*2.5f;
	}

}

StageScene::~StageScene()
{
	Release();
}
