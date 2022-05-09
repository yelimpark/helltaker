#include "LevelEndingScene.h"
#include "../Framework/Framework.h"
#include "../Scene/Scene.h"
#include "../Utils/SceneManager.h"
#include "../Utils/InputManager.h"
#include "../Utils/Utils.h"
#include "../Utils/rapidcsv.h"
#include "TitleScene.h"


LevelEndingScene::LevelEndingScene(SceneManager& sceneManager)
	:Scene(sceneManager), enterCount(0), selectIndex(0)
{
}

void LevelEndingScene::Init()
{
	// background
	bg.setTexture(TextureHolder::GetTexture("Sprite/background.png"));
	hellbackground.setTexture(TextureHolder::GetTexture("Sprite/dialogueBG_hell.png"));
	FloatRect transRect = hellbackground.getLocalBounds();
	hellbackground.setOrigin((transRect.left + transRect.width) * 0.5, (transRect.top + transRect.height) * 0.5f);
	hellbackground.setPosition(resolution.x * 0.5f, resolution.y * 0.4f);

	//top fixtext
	textFix1.setFont(FontHolder::GetFont("Font/CrimsonPro-Medium.ttf"));
	textFix1.setCharacterSize(40);
	textFix1.setFillColor(Color{ 230,77,81 });
	textFix1.setString("Pandemonica, the Tired Demon");
	Utils::SetOrigin(textFix1, Pivots::Center);
	textFix1.setPosition(resolution.x * 0.5, (resolution.y * 0.5) + 160);

	//middle text (can be changed by KeyEnter)
	textFix2[0].setString("Name's Pandemonica, Hell's Cistomer Service.");
	textFix2[1].setString("How may I serve you ?");

	for (int i = 0; i < 2; i++)
	{
		textFix2[i].setFont(FontHolder::GetFont("Font/Amiri-Regular.ttf"));
		textFix2[i].setCharacterSize(30);
		textFix2[i].setFillColor(Color::White);
		Utils::SetOrigin(textFix2[i], Pivots::Center);
		textFix2[i].setPosition(Vector2f(resolution.x / 2, resolution.y / 20 * i + 745));
	
		// Select menubar
		menu[i].setFont(FontHolder::GetFont("Font/Amiri-Regular.ttf"));
		menu[i].setCharacterSize(30);

	}

	//Idle image (can be change to bad image)
	texture = new Texture [2];
	texture[0] = (TextureHolder::GetTexture("Sprite/pand_idle.png")); //good image

	//----------------------------------
	//배열인덱스를 상수를 넣지말고 
	//변수를 선언하고 숫자만큼 엔터치면 드로우를 아예안하게 
	//-----------------------------------------


	//Idle image Size initialization for change
	idle.setTexture(texture[0]);
	auto size = texture[0].getSize();
	idle.setTextureRect(IntRect(0, 0, size.x, size.y));
	Utils::SetOrigin(idle, Pivots::Center);
	idle.setPosition(Vector2f(resolution.x / 2, resolution.y / 22 + 400));

	soundEffects.dialogueStart();

}

void LevelEndingScene::Update(Time& dt)
{
	/*Utils::SetOrigin(textMain, Pivots::Center);
	textMain.setPosition(Vector2f(resolution.x / 2, resolution.y / 20 + 745));*/

	if (InputManager::GetKeyDown(Keyboard::Enter))
	{
		enterCount++;
		soundEffects.dialogueTextEnd();
	}


	 //menu showup
	if (enterCount == 1)
	{
		//enterCount++;
	
		//menu init
		for (int i = 0; i < 2; i++)
		{
			Utils::SetOrigin(menu[1], Pivots::Center);
			menu[1].setPosition(Vector2f(resolution.x / 2, resolution.y / 20 * i + 745));

			Utils::SetOrigin(menu[i], Pivots::Center);
			menu[i].setPosition(Vector2f(resolution.x / 2, resolution.y / 16 * i + 850));
		}
		menu[0].setString("We can figure something out at my place.?");
		menu[1].setString("Maybe I can serve YOU instread?");

		menuimag = new Texture[4];
		auto size = menuimag[2].getSize();
		menuimag[0] = (TextureHolder::GetTexture("Sprite/button0004.png"));
		menuimg_s1.setTexture(menuimag[0]);
		Utils::SetOrigin(menuimg_s1, Pivots::Center);
		menuimg_s1.setPosition(Vector2f(resolution.x / 2, resolution.y / 16 + 860));

		menuimag[1] = (TextureHolder::GetTexture("Sprite/button0004.png"));
		menuimg_s2.setTexture(menuimag[1]);
		Utils::SetOrigin(menuimg_s2, Pivots::Center);
		menuimg_s2.setPosition(Vector2f(resolution.x / 2, resolution.y /700  + 860));

		//menu select moving
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
	}

	else if (enterCount >= 2)
	{
		idle.setTexture(texture[1]);
		switch (GetPressedMenu())
		{
		case 0: //bad
			badMenu();

			if (enterCount == 3)
			{
				death.Init(Vector2f(resolution.x/2.f , resolution.y/2.f));
			}
			if (enterCount >= 3)
			{
				death.Update(dt.asSeconds());
				soundEffects.badEnding();

				if (enterCount >= 5)
				{
					sceneManager.ChangeScene(SceneType::STAGE);
				}
			}
			break;
		case 1: //good
			GoodMenu();
			
			if (enterCount == 3)
			{
				success.Init(Vector2f(resolution.x/2 , resolution.y/1.3 ));
			}
			if (enterCount >= 3)
			{
				success.Update(dt.asSeconds());
				
				if (enterCount >= 5)
				{
					sceneManager.ChangeScene(SceneType::STAGE);
				}
			}
	
			break;
		}
	}
}

void LevelEndingScene::Render()
{
	window.setView(mainView);
	window.draw(bg);
	window.draw(hellbackground);
	window.draw(idle);
	for (int i = 0; i < 2; i++)
	{
		window.draw(textFix2[i]);
		window.draw(menu[i]);
	}
	
	window.draw(menuimg_s1);
	window.draw(menuimg_s2);
	window.draw(textFix1);

	success.Draw(window);
	death.Draw(window);
	
}

void LevelEndingScene::MoveUp()
{
	if (selectIndex - 1 >= 0)
	{
		menu[selectIndex].setFillColor(Color::White);
		menu[selectIndex].setCharacterSize(30);
		selectIndex--;
		menu[selectIndex].setFillColor(Color{ 230,77,81 });
		menu[selectIndex].setCharacterSize(35);
	}
}

void LevelEndingScene::MoveDown()
{
	if (selectIndex + 1 < MAX_NUMBER_OF_SCRIPT)
	{
		menu[selectIndex].setFillColor(Color::White);
		menu[selectIndex].setCharacterSize(30);
		selectIndex++;
		menu[selectIndex].setFillColor(Color{ 230,77,81 });
		menu[selectIndex].setCharacterSize(35);

	}
}

void LevelEndingScene::GoodMenu()
{

	


	textFix2[0].setString("Sweet of you to offer. I could really use some coffee.");
	textFix2[1].setString("I'm not myself without it.");


	menu[0].setString(" ");
	menu[1].setString(" ");

	menuimag[2] = (TextureHolder::GetTexture("Sprite/button0004_s.png"));
	menuimg_s1.setTexture(menuimag[2]);

	menuimag[3] = (TextureHolder::GetTexture("Sprite/button0004_s.png"));
	menuimg_s2.setTexture(menuimag[3]);

	// Need Success image!!!!!!!!!!!!!

	texture[1] = (TextureHolder::GetTexture("Sprite/pand_flust.png")); //good image
	idle.setTexture(texture[1]);
	auto size = texture[1].getSize();
	idle.setTextureRect(IntRect(0, 0, size.x, size.y));


}

void LevelEndingScene::badMenu()
{
	textFix2[0].setString("You thought you're leaving hell alive?");
	textFix2[1].setString("How delusional.");
	
	texture[1] = (TextureHolder::GetTexture("Sprite/pand_idle.png")); 
	idle.setTexture(texture[1]);
	auto size = texture[1].getSize();
	idle.setTextureRect(IntRect(0, 0, size.x, size.y));
}

int LevelEndingScene::GetPressedMenu()
{
	return selectIndex;
}

void LevelEndingScene::Release()
{
}

LevelEndingScene::~LevelEndingScene()
{
}
