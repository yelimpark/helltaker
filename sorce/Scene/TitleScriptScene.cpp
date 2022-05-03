#include "TitleScriptScene.h"
#include "../Framework/Framework.h"
#include "../Scene/Scene.h"
#include "../Utils/SceneManager.h"
#include "../Utils/InputManager.h"

TitleScriptScene::TitleScriptScene(SceneManager& sceneManager)
	:Scene(sceneManager), window(Framework::Getwindow()),
	resolution(Framework::GetResolution()),
	mainView(Framework::GetMainView()), textselectIndex(0)
{

}

void TitleScriptScene::Init()
{
	bg.setTexture(TextureHolder::GetTexture("Sprite/background.png"));

	script[0] = "Story of the HELLTAKER again ? Interesting...";

	script[1] = " DO you, by any charce, need a narrator ? ";

	script[2] = "Why please, allow me. It will be a pleasure.";
	////screen7 showup man
	script[3] = "Why woke up ine day with a dream.";
	script[4] = "Harem full if demon girls";
	////screen8 showup man
	script[5] = "It was, however,not an easy dream to achieve";
	script[6] = "It could cost you your life";
	////screen9 showup man
	script[7] = """It could cost you your life""";
	script[8] = "Ypu said,as you ventured down to hell.";

	//Sprite* img = new Sprite[3];
	//img[0].setTexture(TextureHolder::GetTexture("Sprite/button0004.png"));
	//img[1].setTexture(TextureHolder::GetTexture("Sprite/button0004.png"));
	//img[2].setTexture(TextureHolder::GetTexture("Sprite/button0004.png"));



}

void TitleScriptScene::Update(Time& dt)
{
	if (InputManager::GetKeyDown(Keyboard::Enter))
	{
		textselectIndex++;
		/*sceneManager.ChangeScene(SceneType::ENDINGCUTSCENE);*/
	}
	textintro.setString(script[textselectIndex]);

}

void TitleScriptScene::Render()
{
	window.draw(bg);
	window.draw(textintro);
}

void TitleScriptScene::Release()
{
}

TitleScriptScene::~TitleScriptScene()
{
}
