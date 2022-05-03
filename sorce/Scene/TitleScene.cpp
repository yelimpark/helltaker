#include "TitleScene.h"
#include "../Framework/Framework.h"
#include "../Scene/Scene.h"
#include "../Utils/SceneManager.h"
#include "../Utils/InputManager.h"
#include "../Utils/Utils.h"
#include <iostream>

using namespace std;

TitleScene::TitleScene(SceneManager& sceneManager)
	:Scene(sceneManager),window(Framework::Getwindow()),
	resolution(Framework::GetResolution()),
	mainView(Framework::GetMainView()), enterCount(0), selectIndex(0)
{
}

void TitleScene::Init()
{	
	cloud.setTexture(TextureHolder::GetTexture("Sprite/dialogueBG_abyss.png"));
	bg.setTexture(TextureHolder::GetTexture("Sprite/background.png"));
	
	for (int i = 0; i < 2; i++)
	{
		textOpen[i].setCharacterSize(20);
		textOpen[i].setFont(FontHolder::GetFont("Font/Amiri-Regular.ttf"));
		textOpen[i].setPosition(resolution.x * 0.5, resolution.y * 0.5);
		textOpen[i].setOrigin(textOpen[i].getGlobalBounds().width / 2, textOpen[i].getGlobalBounds().height / 2);
		Utils::SetOrigin(textOpen[i], Pivots::Center);
	}

	Sprite* img = new Sprite[3];
	img[0].setTexture(TextureHolder::GetTexture("Sprite/button0004.png"));
	img[1].setTexture(TextureHolder::GetTexture("Sprite/button0004.png"));
	img[2].setTexture(TextureHolder::GetTexture("Sprite/button0004.png"));


	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		menu[i].setFont(FontHolder::GetFont("Font/CrimsonPro-Medium.ttf"));
		menu[i].setFillColor(Color::White);
		menu[i].setCharacterSize(40);
		menu[i].setOrigin(menu[i].getGlobalBounds().width / 2, menu[i].getGlobalBounds().height / 2);
		menu[i].setPosition(Vector2f(resolution.x / 2, resolution.y / 9 * i +1));
	}

	
	cloud.setOrigin(cloud.getGlobalBounds().width / 2, cloud.getGlobalBounds().height / 2);
	beel.setOrigin(cloud.getGlobalBounds().width / 2, cloud.getGlobalBounds().height / 2);


	textintro.setFont(FontHolder::GetFont("Font/Amiri-Regular.ttf"));
	textintro.setCharacterSize(25);
	textintro.setFillColor(Color::White);
	textintro.setPosition(resolution.x * 0.5, resolution.y * 0.5);
	
	cloud.setPosition(Vector2f(resolution.x / 2, resolution.y / 2.5));
	beel.setPosition(Vector2f(resolution.x / 1.5, resolution.y / 2.5));

	mainView.setCenter(resolution.x * 0.5f, resolution.y * 0.5f);

	textOpen[0].setString("You find yourself surrounded by the\nPress[ENTER or A]to continue.");
	textOpen[1].setString(" ");

	
}

void TitleScene::Update(Time& dt)
{
	
	
	if (InputManager::GetKeyDown(Keyboard::Enter) || InputManager::GetKeyDown(Keyboard::A))
	{
		if (enterCount == 0)
		{
			textOpen[0].setString("");
			textOpen[1].setString("");

			textintro.setString("Beelzebub,The Great Fly");
			Utils::SetOrigin(textintro, Pivots::Center);

			beel.setTexture(TextureHolder::GetTexture("Sprite/beel_fly.png"));
			enterCount++;
		}
		else if (enterCount == 1)
		{
			menu[0].setString("NEW GAME");
			menu[1].setString("CHAPTER SELECT");
			menu[2].setString("EXIT");
			for(int i = 0; i < 3; i++)
			{
				imgMenu.setTexture(TextureHolder::GetTexture("Sprite/button0004.png"));
				Utils::SetOrigin(menu[i], Pivots::Center);
			}
			enterCount++;
		}
	}
	if (enterCount == 2)
	{
		if (InputManager::GetKeyDown(Keyboard::Up))
		{
			MoveUp();
		}
		if (InputManager::GetKeyDown(Keyboard::Down))
		{
			MoveDown();
		}
		if (InputManager::GetKeyDown(Keyboard::Enter))
		{
			switch (GetPressedMenu())
			{
			case 0:
				
				// NEW GAME -> stage (intro script)
				//sceneManager.ChangeScene(SceneType::TITLESCRIPT);
				break;
			case 1:
				// CHAPTER SELECT -> level select scene
				break;
			case 2:
				// EXIT -> finish game
				break;
			}
			delete img;
			

		}
	}
}

void TitleScene::Render()
{
	window.setView(mainView);
	window.draw(bg);
	window.draw(cloud);

	window.draw(textOpen[0]);
	window.draw(textOpen[1]);
	
	window.draw(beel);

	window.draw(textintro);
	window.draw(bu);

	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
	window.draw(imgMenu);
	
}

void TitleScene::MoveUp()
{
	if (selectIndex - 1 >= 0)
	{
		menu[selectIndex].setFillColor(Color::White);
		menu[selectIndex].setCharacterSize(40);
		selectIndex--;
		menu[selectIndex].setFillColor(Color{ 230,77,81 });
		menu[selectIndex].setCharacterSize(50);
	}
}

void TitleScene::MoveDown()
{
	if (selectIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectIndex].setFillColor(Color::White);
		menu[selectIndex].setCharacterSize(40);
		selectIndex++;
		menu[selectIndex].setFillColor(Color{ 230,77,81 });
		menu[selectIndex].setCharacterSize(50);

	}
}

int TitleScene::GetPressedMenu()
{
	return selectIndex;
}

void TitleScene::Release()
{

}

TitleScene::~TitleScene()
{

}
