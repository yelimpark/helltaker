#pragma once
#include "./Scene.h"
#include "../GameObj/CutSceneTransition.h"

class TransitionScene : public Scene 
{
private:
	CutSceneTransition cutTransition;
	SceneType nextScene;

public:
	TransitionScene(SceneManager& sceneManager);

	virtual void Init();

	virtual void Update(Time& dt);

	virtual void Render();

	virtual void Release();

	void SetNext(SceneType to);

	SceneType GetNext();
};