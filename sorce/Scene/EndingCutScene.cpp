#include "EndingCutScene.h"
#include "../Framework/Framework.h"
#include "../Scene/Scene.h"
#include "../Utils/SceneManager.h"
#include "../Utils/InputManager.h"

EndingCutScene::EndingCutScene(SceneManager& sceneManager)
	:Scene(sceneManager), window(Framework::Getwindow()),
	resolution(Framework::GetResolution()),
	mainView(Framework::GetMainView())
{
}

void EndingCutScene::Init()
{
	bg.setTexture(TextureHolder::GetTexture("Sprite/background.png"));
	cloud.setTexture(TextureHolder::GetTexture("Sprite/dialogueBG_hell.png"));

	cloud.setOrigin(cloud.getGlobalBounds().width / 2, cloud.getGlobalBounds().height / 2);
	cloud.setPosition(Vector2f(resolution.x / 2, resolution.y / 2.5));
}

void EndingCutScene::Update(Time& dt)
{
	if (InputManager::GetKeyDown(Keyboard::Enter) || InputManager::GetKeyDown(Keyboard::A)) {
		sceneManager.ChangeScene(SceneType::TITLEMEMU);
	}
}

void EndingCutScene::Render()
{
	window.setView(mainView);
	window.draw(bg);
	window.draw(cloud);
}

void EndingCutScene::Release()
{
}

EndingCutScene::~EndingCutScene()
{
}
