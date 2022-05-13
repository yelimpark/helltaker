#pragma once
#include "./Scene.h"
#include <vector>

class Script;

class LevelEndScene : public Scene 
{
private:
	std::vector<Script*> scripts;
	int idx;

	Sprite background;

public:
	LevelEndScene(SceneManager& sceneManager);

	virtual void Init();

	virtual void Update(Time& dt);

	virtual void Render();

	virtual void Release();

	virtual ~LevelEndScene();
};