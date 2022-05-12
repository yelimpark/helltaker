#include "./SceneManager.h"
#include "../Scene/TitleScene.h"
#include "../Scene/StageScene.h"
#include "../Scene/TitleScriptScene.h"
#include "../Scene/LevelEndingScene.h"
#include "../Resource/TextureHolder.h"
#include "../Scene/LevelEndScene.h"
#include "../Scene/BadEndingScene.h"

void SceneManager::Init()
{
	GameVal::Init();
	currScene = (SceneType)3;
	
	scenes[(int)SceneType::TITLE] = new TitleScene(*this);
	scenes[(int)SceneType::TITLESCRIPT] = new TitleScriptScene(*this);
	scenes[(int)SceneType::STAGE] = new StageScene(*this);
	scenes[(int)SceneType::LEVELENDING] = new LevelEndScene(*this);
	scenes[(int)SceneType::BADENDING] = new BadEndingScene(*this);

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

void SceneManager::Start()
{
	scenes[(int)currScene]->Init();
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
	TextureHolder::Release();
}
