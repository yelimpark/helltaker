#include "./SceneManager.h"
#include "../Scene/TitleScene.h"
#include "../Scene/StageScene.h"
#include "../Resource/TextureHolder.h"
#include "../Scene/CutScene.h"
#include "../Scene/BadEndingScene.h"
#include "../Scene/InitLoadingScene.h"

void SceneManager::Init()
{
	GameVal::Init();
	currScene = (SceneType)0;

	scenes[(int)SceneType::INITLOADING] = new InitLoadingScene(*this);
	scenes[(int)SceneType::TITLE] = new TitleScene(*this);
	scenes[(int)SceneType::STAGE] = new StageScene(*this);
	scenes[(int)SceneType::CUT] = new CutScene(*this);
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

void SceneManager::InitScene(SceneType newScene)
{
	scenes[(int)newScene]->Init();
}

void SceneManager::Render()
{
	scenes[(int)currScene]->Render();
}

void SceneManager::ChangeScene(SceneType newScene)
{
	scenes[(int)currScene]->Release();
	currScene = newScene;
}

SceneManager::~SceneManager()
{
	Release();
	TextureHolder::Release();
}
