#include "./SceneManager.h"
#include "../Scene/TitleScene.h"
#include "../Scene/StageScene.h"
#include "../Resource/TextureHolder.h"
#include "../Scene/CutScene.h"
#include "../Scene/BadEndingScene.h"
#include "../Scene/InitLoadingScene.h"
#include "../Framework/Framework.h"
#include "../Scene/JudgementScene.h"

void SceneManager::Init()
{
	GameVal::Init();
	currScene = (SceneType)5;
	holdScene = SceneType::COUNT;

	scenes[(int)SceneType::INITLOADING] = new InitLoadingScene(*this);
	scenes[(int)SceneType::TITLE] = new TitleScene(*this);
	scenes[(int)SceneType::STAGE] = new StageScene(*this);
	scenes[(int)SceneType::CUT] = new CutScene(*this);
	scenes[(int)SceneType::BADENDING] = new BadEndingScene(*this);
	scenes[(int)SceneType::JUDJEMENT] = new JudgementScene(*this);

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
	if (transitionActive) {
		if (transition.Update(dt.asSeconds())) {
			transitionActive = false;
		}
		if (transition.IsFull()) {
			scenes[(int)currScene]->Release();
			currScene = holdScene;
			scenes[(int)currScene]->Init();
		}
	}
	scenes[(int)currScene]->Update(dt);
}

void SceneManager::InitScene(SceneType newScene)
{
	scenes[(int)newScene]->Init();
}

void SceneManager::Render()
{
	scenes[(int)currScene]->Render();
	if (transitionActive) {
		transition.Draw(Framework::Getwindow());
	}
}

void SceneManager::ChangeScene(SceneType newScene, bool transitionActive)
{
	this->transitionActive = transitionActive;
	if (this->transitionActive) {
		transition.Init();
		holdScene = newScene;
	}
	else {
		scenes[(int)currScene]->Release();
		currScene = newScene;
		scenes[(int)currScene]->Init();
	}
}

SceneManager::~SceneManager()
{
	Release();
	TextureHolder::Release();
}
