#include "StageScene.h"
#include <SFML/Graphics.hpp>
#include "../Framework/Framework.h"
#include "../Utils/rapidcsv.h"
#include "../Utils/InputManager.h"

using namespace sf;

StageScene::StageScene(SceneManager& sceneManager)
	: Scene(sceneManager), lastTurn(23), uiView(Framework::GetUIView()), transHeight(100)
{

}

void StageScene::Init()
{
	spriteBackground.setTexture(TextureHolder::GetTexture("Sprite/chapterBG0001.png"));
	spriteSide1.setTexture(TextureHolder::GetTexture("Sprite/mainUIexport_bUI2.png"));
	spriteSide2.setTexture(TextureHolder::GetTexture("Sprite/mainUIexport_bUI2.png"));
	flameBase1.setTexture(TextureHolder::GetTexture("Sprite/FLAMEbase0001.png"));
	flameBase2.setTexture(TextureHolder::GetTexture("Sprite/FLAMEbase0001.png"));
	transition.setTexture(TextureHolder::GetTexture("Sprite/dialogueBG_hell.png"));
	FloatRect transRect = transition.getLocalBounds();
	transition.setOrigin(transRect.left+transRect.width*0.5, transRect.top + transRect.height * 0.5f);

	//rapidcsv::Document background("data_tables/stage_background_texture.csv");
	//std::vector<std::string>colId = background.GetColumn<std::string>("TEXTURE PATH");

	transeScene = false;

}

void StageScene::Update(Time& dt)
{
	spriteBackground.setPosition(0, 0);
	spriteSide1.setPosition(0, 0);
	spriteSide2.setPosition(resolution.x, 0);
	spriteSide2.setScale(-1.f, 1.f);
	flameBase1.setPosition(625, 268);
	flameBase2.setPosition(1225, 515);

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
	window.draw(flameBase1);
	window.draw(flameBase2);

	window.setView(uiView);
	if (transeScene)
	{
		window.draw(transition);
	}
	ui.Draw(window);
	
}

void StageScene::Release()
{
}

void StageScene::TranseScene(float dt)
{
	transition.setPosition(0, 306);
	transition.setTextureRect( { 0, (int)(544 * 0.5f), resolution.x, (int)transHeight });
	transHeight += dt*100;
}

StageScene::~StageScene()
{
}
