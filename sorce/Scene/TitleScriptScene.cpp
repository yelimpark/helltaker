#include "TitleScriptScene.h"
#include "../Framework/Framework.h"
#include "../Scene/Scene.h"
#include "../Utils/SceneManager.h"
#include "../Utils/InputManager.h"

TitleScriptScene::TitleScriptScene(SceneManager& sceneManager)
	:Scene(sceneManager), window(Framework::Getwindow()),
	resolution(Framework::GetResolution()),
	mainView(Framework::GetMainView())
{


}

void TitleScriptScene::Init()
{
}

void TitleScriptScene::Update(Time& dt)
{
	if (InputManager::GetKeyDown(Keyboard::Enter))
	{
		sceneManager.ChangeScene(SceneType::ENDINGCUTSCENE);
	}
}

void TitleScriptScene::Render()
{
}

void TitleScriptScene::Release()
{
}

TitleScriptScene::~TitleScriptScene()
{
}
