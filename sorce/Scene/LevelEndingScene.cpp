#include "LevelEndingScene.h"
#include "../Framework/Framework.h"
#include "../Scene/Scene.h"
#include "../Utils/SceneManager.h"
#include "../Utils/InputManager.h"
#include "../Utils/Utils.h"

LevelEndingScene::LevelEndingScene(SceneManager& sceneManager)
	:Scene(sceneManager), window(Framework::Getwindow()),
	resolution(Framework::GetResolution()),
	mainView(Framework::GetMainView()), enterCount(0), textselectIndex(0), textureselectIndex(0)
{
}

void LevelEndingScene::Init()
{
	bg.setTexture(TextureHolder::GetTexture("Sprite/background.png"));
	hellbackground.setTexture(TextureHolder::GetTexture("Sprite/dialogueBG_hell.png"));
	hellbackground.setOrigin(hellbackground.getGlobalBounds().width / 2, hellbackground.getGlobalBounds().height / 2);
	hellbackground.setPosition(Vector2f(resolution.x / 2, resolution.y / 2.5));

	//img.setOrigin(hellbackground.getGlobalBounds().width / 2, hellbackground.getGlobalBounds().height / 2);
	//img.setPosition(Vector2f(resolution.x / 2, resolution.y / 2.5));



	interimg = new Texture[6]; //idle[2],menu[2] imgarray
	//button [2]
	interimg[0] = (TextureHolder::GetTexture("Sprite/button0004.png"));
	interimg[1] = (TextureHolder::GetTexture("Sprite/button0003.png"));

	//idle [2]
	interimg[2] = (TextureHolder::GetTexture("Sprite/pand_idle.png")); //normal
	interimg[3] = (TextureHolder::GetTexture("Sprite/pand_flust.png"));//die
	interimg[4] = (TextureHolder::GetTexture("Sprite/success0008.png"));//succ situation
	interimg[5] = (TextureHolder::GetTexture("Sprite/dialogueDeathExport0009.png"));//die situation

	textMain.setCharacterSize(20);
	textMain.setFont(FontHolder::GetFont("Font/Amiri-Regular.ttf"));
	textMain.setPosition(resolution.x * 0.5, resolution.y * 0.5);
	textMain.setOrigin(textMain.getGlobalBounds().width / 2, textMain.getGlobalBounds().height / 2);
	Utils::SetOrigin(textMain, Pivots::Center);

	script[0] = "Name's Pandemonica, Hell's Cistomer Service.\nHow may I serve you ?";

	//menu text you can choice 1,2
	script[1] = "We can figure something out at my place.?"; //1
	script[2] = "Maybe I can serve YOU instread?"; //2
	//answer
	script[3] = "You thought you're leaving hell alive? How delesional."; //1 -> die(change die scene)
	script[4] = "Sweet of you to offer. I could really use some coffee.\nI'm noy myself wirhout it."; //2 -> success 


}

void LevelEndingScene::Update(Time& dt)
{
	if (InputManager::GetKeyDown(Keyboard::Enter))
	{
		textselectIndex++;
		textureselectIndex++;

		textMain.setString(script[textselectIndex]);
		img.setTexture(interimg[textureselectIndex]);
		auto size = interimg[textureselectIndex].getSize();
		img.setTextureRect(IntRect(0, 0, size.x, size.y));
	}

}

void LevelEndingScene::Render()
{
	window.setView(mainView);
	window.draw(bg);
	window.draw(hellbackground);
	window.draw(textMain);

	window.draw(img);
	//마지막입력시 draw 안하게 
}

void LevelEndingScene::MoveUp()
{
}

void LevelEndingScene::MoveDown()
{
}

int LevelEndingScene::GetPressedMenu()
{
	return 0;
}

void LevelEndingScene::Release()
{
}

LevelEndingScene::~LevelEndingScene()
{
}
