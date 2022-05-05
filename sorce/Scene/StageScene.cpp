#include "StageScene.h"
#include <SFML/Graphics.hpp>
#include "../Framework/Framework.h"

#include "../UI/StageUI.h"
#include "../Utils/rapidcsv.h"
#include "../Utils/InputManager.h"
#include "../Utils/Utils.h"
#include "../GameObj/FlameBase.h"

#include <sstream>

using namespace sf;

StageScene::StageScene(SceneManager& sceneManager)
	: Scene(sceneManager), lastTurn(0), level(GameVal::level), transHeight(0), opacity(0)
{

}

void StageScene::Init()
{
	std::map<std::string, LevelData> levelDatas;
	std::map<std::string, std::vector<FlameBaseData>> flameBaseDatas;

	Utils::CsvToStruct<LevelData>(levelDatas, "./LevelInfo/LevelInfo.csv");
	Utils::CsvToStructVectorMap<FlameBaseData>(flameBaseDatas, "./LevelInfo/FlameBaseInfo.csv");

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
	transBack.setSize(Vector2f(resolution.x, resolution.y));
	transBack.setFillColor(Color::Transparent);

	spriteBackground.setPosition(levelData.BgPosX, levelData.BgPosY);
	spriteSide1.setPosition(0, 0);
	spriteSide2.setPosition(resolution.x, 0);
	spriteSide2.setScale(-1.f, 1.f);

	int idx = 0;
	for (auto flameBase : flameBases) {
		flameBase->Init(flameBaseDatas[ss.str()][idx].x, flameBaseDatas[ss.str()][idx].y);
		++idx;
	}

	boxInfo boxInfos;
	boxInfos.position = Vector2f(644, 577);
	boxInfos.textureFilename = "Sprite/boxExport0001.png";
	boxdatas.push_back(boxInfos);
	boxInfos.position = Vector2f(800, 577);
	boxInfos.textureFilename = "Sprite/boxExport0003.png";
	boxdatas.push_back(boxInfos);
	boxInfos.position = Vector2f(900, 407);
	boxInfos.textureFilename = "Sprite/boxExport0004.png";
	boxdatas.push_back(boxInfos);
	boxInfos.position = Vector2f(1200, 607);
	boxInfos.textureFilename = "Sprite/boxExport0008.png";
	boxdatas.push_back(boxInfos);

	ui.Init();
	

	player.Init(1150, 290);

	transeScene = false;
	StageUI::isMovedSide = false;
}

void StageScene::Update(Time& dt)
{
	for (auto flameBase : flameBases) {
		flameBase->Update(dt.asSeconds());
	}

	player.Update(dt.asSeconds());

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
	window.draw(spriteBackground);
	window.draw(spriteSide1);
	window.draw(spriteSide2);

	for (auto flameBase : flameBases) {
		flameBase->Draw(window);
	}

	for (auto& boxdatas : boxes)
	{
		boxdatas->Draw(window);
	}

	player.Draw(window);

	if (transeScene)
	{
		window.draw(transBack);
		window.draw(transition);
	}
	ui.Render(window);
	
}

void StageScene::Release()
{
	for (auto flameBase : flameBases) {
		delete flameBase;
	}
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
		return;
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
