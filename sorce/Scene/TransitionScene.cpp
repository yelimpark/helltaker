#include "TransitionScene.h"

TransitionScene::TransitionScene(SceneManager& sceneManager)
	:Scene(sceneManager), nextScene(SceneType::COUNT)
{
}

void TransitionScene::Init()
{
	cutTransition.Init();
}

void TransitionScene::Update(Time& dt)
{
	if (cutTransition.Update(dt.asSeconds()))
		nextScene = SceneType::COUNT;
	if (cutTransition.IsFull())
		sceneManager.Start();
}

void TransitionScene::Render()
{
	cutTransition.Draw(window);
}

void TransitionScene::Release()
{
}

void TransitionScene::SetNext(SceneType to)
{
	nextScene = to;
}

SceneType TransitionScene::GetNext()
{
	return nextScene;
}
