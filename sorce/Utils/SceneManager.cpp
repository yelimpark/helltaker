#include "./SceneManager.h"
#include "../Scene/TitleScene.h"

void SceneManager::Init()
{
	GameVal::Init();

	scenes[(int)SceneType::TITLE] = new TitleScene(*this);

	scenes[(int)currScene]->Init();
}

void SceneManager::Release()
{
	for (int i = 0; i < (int)SceneType::COUNT; i++) {
		if (scenes[i] != nullptr)
			delete scenes[i];
	}
}

void SceneManager::Update(Time& dt)
{
	scenes[(int)currScene]->Update(dt);
}

void SceneManager::Render()
{
	scenes[(int)currScene]->Render();
}

void SceneManager::ChangeScene(SceneType newScene)
{
	scenes[(int)currScene]->Release();
	currScene = newScene;
	scenes[(int)currScene]->Init();
}

SceneManager::~SceneManager()
{
	Release();
}
