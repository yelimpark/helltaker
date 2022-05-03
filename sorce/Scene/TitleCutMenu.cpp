#include "TitleCutMenu.h"
#include "../Framework/Framework.h"
#include "../Scene/Scene.h"
#include "../Utils/SceneManager.h"
#include "../Utils/InputManager.h"

using namespace std;
TitleCutMenu::TitleCutMenu(SceneManager& sceneManager)
	:Scene(sceneManager), window(Framework::Getwindow()),
	resolution(Framework::GetResolution()),
	mainView(Framework::GetMainView())
{
}

void TitleCutMenu::Init()
{

	bg.setTexture(TextureHolder::GetTexture("Sprite/background.png"));
	cloud.setTexture(TextureHolder::GetTexture("Sprite/dialogueBG_abyss.png"));
	beel.setTexture(TextureHolder::GetTexture("Sprite/beel_fly.png"));

	cloud.setOrigin(cloud.getGlobalBounds().width / 2, cloud.getGlobalBounds().height / 2);
	beel.setOrigin(cloud.getGlobalBounds().width / 2, cloud.getGlobalBounds().height / 2);


	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		menu[i].setFont(FontHolder::GetFont("Font/CrimsonPro-Medium.ttf"));
		menu[i].setFillColor(Color::White);
		menu[i].setCharacterSize(40);
		menu[i].setOrigin(menu[i].getGlobalBounds().width / 2, menu[i].getGlobalBounds().height / 2);
		menu[i].setPosition(Vector2f(resolution.x / 2, resolution.y / (MAX_NUMBER_OF_ITEMS + 1) * i + 1));
	
		

		munuwhite[i].setTexture(TextureHolder::GetTexture("Sprite/button0004.png"));
		munured[i].setTexture(TextureHolder::GetTexture("Sprite/button0004_r.png"));

		munuwhite[i].setPosition(resolution.x * 0.15, resolution.y * 0.13);
		munured[i].setPosition(resolution.x * 0.15, resolution.y * 0.13);

	}

	menu[0].setString("NEW GAME");
	menu[1].setString("CHAPTER SELECT");
	menu[2].setString("EXIT");

	textTop.setFont(FontHolder::GetFont("Font/CrimsonPro-Medium.ttf"));
	textTop.setString("Breelzebub, The Great Fly");

	textTop.setPosition(resolution.x * 0.41f, resolution.y * 0.6);
	textTop.setCharacterSize(35);
	textTop.setFillColor(Color{ 230,77,81 });

	beel.setPosition(Vector2f(resolution.x / 1.5, resolution.y / 2.5));
	cloud.setPosition(Vector2f(resolution.x / 2, resolution.y / 2.5));
}

void TitleCutMenu::Update(Time& dt)
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
			// NEW GAME -> stage 
			break;
		case 1:
			// CHAPTER SELECT -> level select scene
			break;
		case 2:
			// EXIT -> finish game

			break;
			
		}
		sceneManager.ChangeScene(SceneType::TITLESCRIPT);
	}
}


void TitleCutMenu::Render()
{
	window.setView(mainView);
	window.draw(bg);
	window.draw(cloud);
	window.draw(beel);
	window.draw(textTop);

	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
		window.draw(munuwhite[i]);
		window.draw(munured[i]);
	}

}

void TitleCutMenu::MoveUp()
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

void TitleCutMenu::MoveDown()
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

int TitleCutMenu::GetPressedMenu()
{
	return selectIndex;
}

void TitleCutMenu::Release()
{
}

TitleCutMenu::~TitleCutMenu()
{
}
