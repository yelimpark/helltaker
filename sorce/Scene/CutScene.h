#pragma once
#include "./Scene.h"
#include "../GameObj/CutSceneTransition.h"
#include <vector>

class Script;

class CutScene : public Scene 
{
private:
	std::vector<Script*> scripts;
	int idx;

	RectangleShape bgColor;

public:
	CutScene(SceneManager& sceneManager);

	virtual void Init();

	virtual void Update(Time& dt);

	virtual void Render();

	virtual void Release();

	virtual ~CutScene();
};