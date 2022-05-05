#pragma once
#include "./Scene.h"
#include "../UI/StageUI.h"
#include "../SceneInitializer/StageSceneInitializer.h"
#include "../GameObj/Player.h"
#include <list>
#include <iostream>

class FlameBase;

class StageScene : public Scene
{
private:
	StageUI ui;

	int level;
	
	std::list<FlameBase *> flameBases;
	Sprite spriteBackground;
	Sprite spriteSide1;
	Sprite spriteSide2;
	Sprite transition;
	Player player;

	int lastTurn;
	float transHeight;

	bool transeScene;

public:
	StageScene(SceneManager& sceneManager);
	virtual void Init();
	virtual void Update(Time& dt);
	virtual void Render();
	virtual void Release();
	void TranseScene(float dt);
	virtual ~StageScene();
};

