#include "TitleScene.h"
#include "../Framework/Framework.h"
#include "../Scene/Scene.h"
#include "../Utils/SceneManager.h"
#include "../Utils/InputManager.h"
#include "../Utils/Utils.h"

using namespace std;

TitleScene::TitleScene(SceneManager& sceneManager)
	:Scene(sceneManager),window(Framework::Getwindow()),
	resolution(Framework::GetResolution()),
	mainView(Framework::GetMainView()), enterCount(0), selectIndex(0)
{
}

void TitleScene::Init()
{	
	Texture& tex = TextureHolder::GetTexture("Sprite/dialogueBG_hell.png");
	tex.setRepeated(true);
	testSprite.setTexture(tex);
	testSprite.setPosition(0, 0);
	for (int i = 0; i < 3; i++) {
		cloud[i].setTexture(TextureHolder::GetTexture("Sprite/dialogueBG_abyss.png"));
		//cloud[i].setOrigin(cloud[i].getGlobalBounds().width, cloud[i].getGlobalBounds().height);
		cloudPosition[i] = Vector2f((-i) * cloud[1].getGlobalBounds().width, resolution.y / 7);
		//beel.setOrigin(cloud[i].getGlobalBounds().width / 2, cloud[i].getGlobalBounds().height / 2);
	}
	bg.setTexture(TextureHolder::GetTexture("Sprite/background.png"));
	
	for (int i = 0; i < 2; i++)
	{
		textOpen[i].setCharacterSize(20);
		textOpen[i].setFont(FontHolder::GetFont("Font/Amiri-Regular.ttf"));
		textOpen[i].setPosition(resolution.x * 0.5, resolution.y * 0.5);
		textOpen[i].setOrigin(textOpen[i].getGlobalBounds().width / 2, textOpen[i].getGlobalBounds().height / 2);
		Utils::SetOrigin(textOpen[i], Pivots::Center);
	}

	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		menu[i].setFont(FontHolder::GetFont("Font/CrimsonPro-Medium.ttf"));
		menu[i].setFillColor(Color::White);
		menu[i].setCharacterSize(40);
		menu[i].setOrigin(menu[i].getGlobalBounds().width / 2, menu[i].getGlobalBounds().height / 2);
		menu[i].setPosition(Vector2f(resolution.x / 2, resolution.y / 9 * i +1));

		img[i].setPosition(Vector2f(resolution.x / 2, resolution.y / 2.5 * i + 1));
	}
	textintro.setFont(FontHolder::GetFont("Font/Amiri-Regular.ttf"));
	textintro.setCharacterSize(25);
	textintro.setFillColor(Color::White);
	textintro.setPosition(resolution.x * 0.5, resolution.y * 0.5);

	for (int i = 0; i < 3; i++) {
		cloud[i].setPosition(cloudPosition[i]);
	}
	
	beel.setPosition(resolution.x * 0.18f, resolution.y / 7.f);

	mainView.setCenter(resolution.x * 0.5f, resolution.y * 0.5f);

	textOpen[0].setString("You find yourself surrounded by the\nPress[ENTER or A]to continue.");
	Utils::SetOrigin(textintro, Pivots::Center);

	speed = 80.f;
}

void TitleScene::Update(Time& dt)
{
	IntRect bound = testSprite.getTextureRect();
	bound.left += 10;
	testSprite.setTextureRect(bound);


	for (int i = 0; i < 3; i++) {
		cloudPosition[i].x += dt.asSeconds() * speed;
		cloud[i].setPosition(cloudPosition[i]);
	}


	if (InputManager::GetKeyDown(Keyboard::Enter) || InputManager::GetKeyDown(Keyboard::A))
	{
		enterCount++;
	}

	if (enterCount == 1)
	{
		textOpen[0].setString("");

		textintro.setString("Beelzebub,The Great Fly");
		textOpen[1].setString("Greethings little one, Please don't mind me.\nIt is just I, good old Beelzebub.");

		beel.setTexture(TextureHolder::GetTexture("Sprite/beel_fly.png"));
	}
	else if (enterCount >= 2)
	{
		textOpen[1].setString("");
		menu[0].setString("NEW GAME");
		menu[1].setString("CHAPTER SELECT");
		menu[2].setString("EXIT");

		for (int i = 0; i < 3; i++)
		{
			img[i].setTexture(TextureHolder::GetTexture("Sprite/button0004.png"));
			Utils::SetOrigin(menu[i], Pivots::Center);
		}
		if (InputManager::GetKeyDown(Keyboard::Up))
		{
			MoveUp();
		}
		if (InputManager::GetKeyDown(Keyboard::Down))
		{
			MoveDown();
		}

		if (enterCount > 2 && InputManager::GetKeyDown(Keyboard::Enter))
		{
			switch (GetPressedMenu())
			{
			case 0:
				sceneManager.ChangeScene(SceneType::TITLESCRIPT);
				// NEW GAME -> stage (intro script)
				break;
			case 1:
				// CHAPTER SELECT -> level select scene
				break;
			case 2:
				// EXIT -> finish game
				break;
			}

		}
	}
	
}

void TitleScene::Render()
{
	window.setView(mainView);
	window.draw(bg);
	for (int i = 0; i < 3; i++)
	{
		window.draw(cloud[i]);
	}
	window.draw(testSprite);

	
	window.draw(beel);

	window.draw(textOpen[0]);
	window.draw(textOpen[1]);

	window.draw(textintro);
	window.draw(bu);

	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
		window.draw(img[i]);
	}

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
