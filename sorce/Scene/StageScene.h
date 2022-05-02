#pragma once
#include "./Scene.h"

class StageScene : public Scene
{
private:
	Sprite sprite;

public:
	StageScene(SceneManager& sceneManager);
	virtual void Init();
	virtual void Update(Time& dt);
	virtual void Render();
	virtual void Release();
	virtual ~StageScene();
};

