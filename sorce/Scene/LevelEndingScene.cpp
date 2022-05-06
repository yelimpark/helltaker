#include "LevelEndingScene.h"
#include "../Framework/Framework.h"
#include "../Scene/Scene.h"
#include "../Utils/SceneManager.h"
#include "../Utils/InputManager.h"
#include "../Utils/Utils.h"
#include "TitleScene.h"

LevelEndingScene::LevelEndingScene(SceneManager& sceneManager)
	:Scene(sceneManager), window(Framework::Getwindow()),
	resolution(Framework::GetResolution()),
	mainView(Framework::GetMainView()), enterCount(0), selectIndex(0)
{
	
}

void LevelEndingScene::Init()
{
	bg.setTexture(TextureHolder::GetTexture("Sprite/background.png"));
	hellbackground.setTexture(TextureHolder::GetTexture("Sprite/dialogueBG_hell.png"));
	FloatRect transRect = hellbackground.getLocalBounds();
	hellbackground.setOrigin((transRect.left + transRect.width) * 0.5, (transRect.top + transRect.height) * 0.5f);
	hellbackground.setPosition(resolution.x * 0.5f, resolution.y * 0.4f);

	textFix1.setFont(FontHolder::GetFont("Font/CrimsonPro-Medium.ttf"));
	textFix1.setCharacterSize(40);
	textFix1.setFillColor(Color{ 230,77,81 });
	textFix1.setString("Pandemonica, the Tired Demon");
	Utils::SetOrigin(textFix1, Pivots::Center);
	textFix1.setPosition(resolution.x * 0.5, (resolution.y * 0.5) + 160);

	Texture& tex = TextureHolder::GetTexture("Sprite/pand_idle.png");
	tex.setRepeated(true);
	idle[0].setTexture(tex);

	textFix2[0].setString("Name's Pandemonica, Hell's Cistomer Service.");
	textFix2[1].setString("How may I serve you ?");

	//menu text you can choice 1,2



	for (int i = 0; i < 2; i++)
	{
		textFix2[i].setCharacterSize(30);
		textFix2[i].setFont(FontHolder::GetFont("Font/Amiri-Regular.ttf"));
		Utils::SetOrigin(textFix2[i], Pivots::Center);
		textFix2[i].setPosition(Vector2f(resolution.x / 2, resolution.y / 22 * i + 745));
		textFix2[i].setFillColor(Color::White);

		idle[i].setPosition(resolution.x/2.5, resolution.y / 10);

		menu[i].setFont(FontHolder::GetFont("Font/Amiri-Regular.ttf"));
		menu[i].setCharacterSize(30);
	
	}

	
	
	//interimg = new Texture[2]; //idle[2],menu[2] imgarray

	//idle [2]
	//interimg[0] = (TextureHolder::GetTexture("Sprite/success0008.png"));//succ situation
	//interimg[2] = (TextureHolder::GetTexture("Sprite/dialogueDeathExport0009.png"));//die situation


	//textMain.setFont(FontHolder::GetFont("Font/CrimsonPro-Medium.ttf"));
	//textMain.setCharacterSize(30);

	//answer
	//script[3] = "You thought you're leaving hell alive? How delesional."; //1 -> die(change die scene)
	//script[4] = "Sweet of you to offer. I could really use some coffee.\n                         I'm noy myself wirhout it."; //2 -> success 


}

void LevelEndingScene::Update(Time& dt)
{

	IntRect bound = idle[0].getTextureRect();
	bound.left += 1;
	idle[0].setTextureRect(bound);
	
	/*Utils::SetOrigin(textMain, Pivots::Center);
	textMain.setPosition(Vector2f(resolution.x / 2, resolution.y / 20 + 745));*/

	if (InputManager::GetKeyDown(Keyboard::Enter))
	{
		enterCount++;
	}

	 //menu showup
	if (enterCount == 1)
	{
		//enterCount++;
		menu[0].setString("We can figure something out at my place.?");
		menu[1].setString("Maybe I can serve YOU instread?");

		//menu init
		for (int i = 0; i < 2; i++)
		{
			Utils::SetOrigin(menu[i], Pivots::Center);
			menu[i].setPosition(Vector2f(resolution.x / 2, resolution.y / 16 * i + 850));

			img[i].setTexture(TextureHolder::GetTexture("Sprite/button0004.png"));
			img[i].setColor({ 255, 255, 255, 150 });
			Utils::SetOrigin(img[i], Pivots::Center);
			img[i].setPosition(Vector2f(resolution.x / 2, resolution.y / 16 * i + 860));
		}

		//menu select moving
		if (InputManager::GetKeyDown(Keyboard::Up))
		{
			MoveUp();
		}
		if (InputManager::GetKeyDown(Keyboard::Down))
		{
			MoveDown();
		}

	}


	else if (enterCount >= 2 && InputManager::GetKeyDown(Keyboard::Enter))
	{
		switch (GetPressedMenu())
		{
		case 0:
			cout << "11111ют╥б!!!!!!!!!";
			idle[0].setTexture(TextureHolder::GetTexture("Sprite/pand_flust.png")); 
			
		
			//sceneManager.ChangeScene(SceneType::TITLE);
			// NEW GAME -> stage (intro script)
			break;
		case 1:
			textFix2[0].setString("Sweet of you to offer.I could really use some coffee.");
			textFix2[1].setString("I'm not myself without it.");

			menu[0].setString(" ");
			menu[1].setString(" ");

			/*auto size = idle[0].getScale();
			idle[0].setTextureRect(IntRect(0, 0, size.x, size.y));*/

			idle[0].setTexture(TextureHolder::GetTexture("Sprite/pand_flust.png"));
			img[0].setTexture(TextureHolder::GetTexture("Sprite/success0006.png "));
			img[1].setTexture(TextureHolder::GetTexture("Sprite/success0006.png "));
		
			//sceneManager.ChangeScene(SceneType::STAGE);
			// CHAPTER SELECT -> level select scene
			break;
		}
		
	}
	else if (enterCount > 5)
	{
		return;
	}
	
	//if (enterCount >= 2)
	//{
	//	textFix2[0].setString("");
	//	textFix2[1].setString("");
	//}
	
	/*	textselectIndex++;
		textureselectIndex++; 

		textMain.setString(script[textselectIndex]);

		img1.setTexture(interimg[textureselectIndex]);
		auto size = interimg[textureselectIndex].getSize();
		img1.setTextureRect(IntRect(0, 0, size.x, size.y));
	}*/


}

void LevelEndingScene::Render()
{
	window.setView(mainView);
	window.draw(bg);
	window.draw(hellbackground);

	for (int i = 0; i < 2; i++)
	{
		window.draw(idle[i]);
		window.draw(textFix2[i]);
		window.draw(menu[i]);
		window.draw(img[i]);
	}
	window.draw(textFix1);
	
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
