#include "StageScene.h"
#include <SFML/Graphics.hpp>
#include "../Framework/Framework.h"
#include "../Utils/rapidcsv.h"
#include "../Utils/InputManager.h"
#include "../Utils/Utils.h"
#include "../GameObj/FlameBase.h"

#include <sstream>

using namespace sf;

StageScene::StageScene(SceneManager& sceneManager)
	: Scene(sceneManager), lastTurn(0), level(GameVal::level), transHeight(100)
{
	Utills::CsvToStruct<LevelData>(levelDatas, "./LevelInfo/LevelInfo.csv");
	Utills::CsvToStructVectorMap<FlameBaseData>(flameBaseDatas, "./LevelInfo/FlameBaseInfo.csv");
}

void StageScene::Init()
{
	stringstream ss;
	ss << level;
	LevelData levelData = levelDatas[ss.str()];

	lastTurn = levelData.lastTurn;

	for (int i = 0; i < flameBaseDatas[ss.str()].size(); ++i) {
		FlameBase* flameBase = new FlameBase();
		flameBases.push_back(flameBase);
	}

	spriteBackground.setTexture(TextureHolder::GetTexture(levelData.BgFilename));
	spriteSide1.setTexture(TextureHolder::GetTexture("Sprite/mainUIexport_bUI2.png"));
	spriteSide2.setTexture(TextureHolder::GetTexture("Sprite/mainUIexport_bUI2.png"));
	transition.setTexture(TextureHolder::GetTexture("Sprite/dialogueBG_hell.png"));
	FloatRect transRect = transition.getLocalBounds();
	transition.setOrigin(transRect.left+transRect.width*0.5, transRect.top + transRect.height * 0.5f);

	spriteBackground.setPosition(levelData.BgPosX, levelData.BgPosY);
	spriteSide1.setPosition(0, 0);
	spriteSide2.setPosition(resolution.x, 0);
	spriteSide2.setScale(-1.f, 1.f);

	int idx = 0;
	for (auto flameBase : flameBases) {
		flameBase->Init(flameBaseDatas[ss.str()][idx].x, flameBaseDatas[ss.str()][idx].y);
		++idx;
	}

	player.Init(1150, 290);

	transeScene = false;
}

void StageScene::Update(Time& dt)
{
	for (auto flameBase : flameBases) {
		flameBase->Update(dt.asSeconds());
	}

	player.Update(dt.asSeconds());

	ui.Update(lastTurn, resolution);

	if (InputManager::GetKeyDown(Keyboard::Enter))
	{
		transeScene = true;

	}

	if (transeScene)
	{
		TranseScene(dt.asSeconds());
	}
	//csv 파일로 끌어와서 작업 할 수 있도록!!!
}

void StageScene::Render()
{
	window.setView(mainView);
	window.draw(spriteBackground);
	window.draw(spriteSide1);
	window.draw(spriteSide2);

	for (auto flameBase : flameBases) {
		flameBase->Draw(window);
	}

	player.Draw(window);

	if (transeScene)
	{
		window.draw(transition);
	}
	ui.Draw(window);
	
}

void StageScene::Release()
{
	for (auto flameBase : flameBases) {
		delete flameBase;
	}
}

void StageScene::TranseScene(float dt)
{
	transition.setPosition(0, 306);
	transition.setTextureRect( { 0, (int)(544 * 0.5f), resolution.x, (int)transHeight });
	transHeight += dt*100;
}

StageScene::~StageScene()
{
	Release();
}
