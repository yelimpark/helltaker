#pragma once
#include "./Scene.h"

class StageScene : public Scene
{
private:

public:
	StageScene(SceneManager& sceneManager);
	void Init();
	void Update();
	void Render();
};

