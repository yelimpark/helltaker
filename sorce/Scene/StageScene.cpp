#include "StageScene.h"
#include <SFML/Graphics.hpp>
#include "../Framework/Framework.h"
#include "../Utils/rapidcsv.h"
#include "../Utils/InputManager.h"
#include "../Utils/Utils.h"

using namespace sf;

StageScene::StageScene(SceneManager& sceneManager)
	: Scene(sceneManager), lastTurn(23), uiView(Framework::GetUIView()), level(0), transHeight(0), opacity(0)
{

}

void StageScene::Init()
{
	Utills::CsvToStruct<LevelData>(levelDataList, "./LevelInfo/LevelInfo.csv");
	list<LevelData>::iterator iter = levelDataList.begin();
	std::advance(iter, level);

	spriteBackground.setTexture(TextureHolder::GetTexture((*iter).BgFilename));
	spriteSide1.setTexture(TextureHolder::GetTexture("Sprite/mainUIexport_bUI2.png"));
	spriteSide2.setTexture(TextureHolder::GetTexture("Sprite/mainUIexport_bUI2.png"));
	flameBase1.setTexture(TextureHolder::GetTexture("Sprite/FLAMEbase0001.png"));
	flameBase2.setTexture(TextureHolder::GetTexture("Sprite/FLAMEbase0001.png"));
	transition.setTexture(TextureHolder::GetTexture("Sprite/dialogueBG_hell.png"));
	FloatRect transRect = transition.getLocalBounds();
	transition.setOrigin(transRect.left+transRect.width*0.5, transRect.top + transRect.height * 0.5f);
	transBack.setSize(Vector2f(resolution.x, resolution.y));
	transBack.setFillColor(Color::Transparent);

	spriteBackground.setPosition((*iter).BgPosX, (*iter).BgPosY);
	spriteSide1.setPosition(0, 0);
	spriteSide2.setPosition(resolution.x, 0);
	spriteSide2.setScale(-1.f, 1.f);
	flameBase1.setPosition(625, 268);
	flameBase2.setPosition(1225, 515);
	transBack.setPosition((*iter).BgPosX, (*iter).BgPosY);

	transeScene = false;
}

void StageScene::Update(Time& dt)
{
	ui.Update(lastTurn, resolution);

	if (InputManager::GetKeyDown(Keyboard::Enter))
	{
		transeScene = true;
	}

	if (transeScene)
	{
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
	window.draw(flameBase1);
	window.draw(flameBase2);

	window.setView(uiView);
	if (transeScene)
	{
		window.draw(transBack);
		window.draw(transition);
	}
	ui.Draw(window);
	
}

void StageScene::Release()
{
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
}
