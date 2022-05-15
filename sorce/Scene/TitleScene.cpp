#include "TitleScene.h"
#include "../Framework/Framework.h"
#include "../Scene/Scene.h"
#include "../Utils/SceneManager.h"
#include "../Utils/InputManager.h"
#include "../Utils/Utils.h"

using namespace std;

TitleScene::TitleScene(SceneManager& sceneManager)
	:Scene(sceneManager), enterCount(0), selectIndex(0), chapterselect(sceneManager)
{
}

void TitleScene::Init()
{
	selectIndex = 0;

	Texture& tex = TextureHolder::GetTexture("Sprite/dialogueBG_abyss_s.png");
	tex.setRepeated(true);
	cloudBackground.setTexture(tex);

	FloatRect transRect = cloudBackground.getLocalBounds();
	cloudBackground.setOrigin((transRect.left + transRect.width) * 0.5, (transRect.top + transRect.height) * 0.5f);
	cloudBackground.setPosition(resolution.x * 0.5f, resolution.y * 0.4f);

	bg.setTexture(TextureHolder::GetTexture("Sprite/background.png"));
	beel.setOrigin((transRect.left + transRect.width) * 0.5, (transRect.top + transRect.height) * 0.5f);

	textOpen1[0].setString("You find yourself surrounded by the");
	textOpen1[1].setString("Press[ENTER or A]to continue.");

	for (int i = 0; i < 2; i++)
	{
		textOpen1[i].setCharacterSize(30);
		textOpen1[i].setFont(FontHolder::GetFont("Font/Amiri-Regular.ttf"));
		Utils::SetOrigin(textOpen1[i], Pivots::Center);
		textOpen1[i].setPosition(Vector2f(resolution.x / 2, resolution.y / 20 * i + 745));

		textOpen2[i].setCharacterSize(30);
		textOpen2[i].setFont(FontHolder::GetFont("Font/Amiri-Regular.ttf"));
	}

	script[0] = "Story of the HELLTAKER again ? Interesting...";
	script[1] = " DO you, by any charce, need a narrator ? ";

	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		menu[i].setFont(FontHolder::GetFont("Font/CrimsonPro-Medium.ttf"));
		menu[i].setFillColor(Color::White);
		menu[i].setCharacterSize(35);
		img[i].setColor({ 99, 61, 74, 225 });
	}
	textFix.setFont(FontHolder::GetFont("Font/CrimsonPro-Medium.ttf"));
	textFix.setCharacterSize(40);
	textFix.setFillColor(Color{ 230,77,81 });

	boo.Init(Vector2f(resolution.x, resolution.y));
	InitMenu();

}

void TitleScene::InitMenu()
{
	MovingMenu();
	selectIndex = 0;
	MovingMenuChange();
}

void TitleScene::MenuUpdate()
{
	textOpen1[0].setString("");
	textOpen1[1].setString("");

	textFix.setString("Beelzebub, The Great Fly");
	Utils::SetOrigin(textFix, Pivots::Center);
	textFix.setPosition(resolution.x * 0.5, (resolution.y * 0.5) + 150);

	textOpen2[0].setString("Greethings little one, Please don't mind me.");
	textOpen2[1].setString("It is just I, good old Beelzebub.");
	for (int i = 0; i < 2; i++)
	{
		Utils::SetOrigin(textOpen2[i], Pivots::Center);
		textOpen2[i].setPosition(Vector2f(resolution.x / 2, resolution.y / 20 * i + 745));
	}

	beel.setTexture(TextureHolder::GetTexture("Sprite/beel_fly.png"));
	Utils::SetOrigin(beel, Pivots::Center);
	beel.setScale(0.98f, 0.98f);
	beel.setPosition(Vector2f(resolution.x * 0.52f, resolution.y * 0.33f));
}

void TitleScene::Update(Time& dt)
{
	IntRect bound = cloudBackground.getTextureRect();
	bound.left += 1;
	cloudBackground.setTextureRect(bound);


	if (InputManager::GetKeyDown(Keyboard::Enter) || InputManager::GetKeyDown(Keyboard::A))
	{
		enterCount++;
	}

	if (enterCount == 1)
	{
		MenuUpdate();
	}

	else if (enterCount >= 2)
	{
		textOpen2[0].setString("");
		textOpen2[1].setString("");

		menu[0].setString("NEW GAME");
		menu[1].setString("CHAPTER SELECT");
		menu[2].setString("EXIT");

		for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
		{
			img[i].setTexture(TextureHolder::GetTexture("Sprite/button0004.png"));
			Utils::SetOrigin(menu[i], Pivots::Center);
			menu[i].setPosition(Vector2f(resolution.x / 2, resolution.y / 12 * i + 750));

			Utils::SetOrigin(img[i], Pivots::Center);
			img[i].setPosition(Vector2f(resolution.x / 2, resolution.y / 12 * i + 765));
		}

		if (InputManager::GetKeyDown(Keyboard::Up))
		{
			MoveUp();
			soundEffects.menuHighlight();
		}
		if (InputManager::GetKeyDown(Keyboard::Down))
		{
			MoveDown();
			soundEffects.menuHighlight();
		}
		if (enterCount >= 3 && InputManager::GetKeyDown(Keyboard::Enter))
		{
			switch (GetPressedMenu())
			{
			case 0:
				soundEffects.menuConfirm();
				sceneManager.ChangeScene(SceneType::STAGE);
				break;
			case 1:
				sceneManager.ChangeScene(SceneType::CHAPTER);
				break;
			case 2:
				//Ending
				window.close();
				break;
			}
		}
	}
	boo.Update(dt.asSeconds());
}

void TitleScene::MovingMenu()
{
	menu[selectIndex].setFillColor(Color{ 255, 255, 255, 128 });
	menu[selectIndex].setCharacterSize(40);
	img[selectIndex].setScale(Vector2f(1, 1));
	img[selectIndex].setColor({ 99, 61, 74, 225 });
}

void TitleScene::MovingMenuChange()
{
	menu[selectIndex].setFillColor(Color{ 255, 255, 255, 225 });
	menu[selectIndex].setCharacterSize(42);
	img[selectIndex].setScale(Vector2f(1.05, 1.05));
	img[selectIndex].setColor({ 230, 77, 81, 225 });
}

void TitleScene::MoveUp()
{
	if (selectIndex - 1 >= 0)
	{
		MovingMenu();
		selectIndex--;
		MovingMenuChange();
	}
}

void TitleScene::MoveDown()
{
	if (selectIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		MovingMenu();
		selectIndex++;
		MovingMenuChange();

	}
}

void TitleScene::Render()
{
	window.setView(mainView);
	window.draw(bg);
	window.draw(cloudBackground);

	window.draw(beel);
	for (int i = 0; i < 2; i++)
	{
		window.draw(textOpen1[i]);
		window.draw(textOpen2[i]);
	}

	window.draw(textFix);

	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
		window.draw(img[i]);
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
