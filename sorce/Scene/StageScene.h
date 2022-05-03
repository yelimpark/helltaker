#pragma once
#include "./Scene.h"
#include "../UI/StageUI.h"

class StageScene : public Scene
{
private:
	StageUI ui;

	Sprite spriteBackground;
	Sprite spriteSide1;
	Sprite spriteSide2;
	Sprite flameBase1;
	Sprite flameBase2;
	Sprite transition;

	int lastTurn;
	float transHeight;

	bool transeScene;

	View uiView;

public:
	StageScene(SceneManager& sceneManager);
	virtual void Init();
	virtual void Update(Time& dt);
	virtual void Render();
	virtual void Release();
	void TranseScene(float dt);
	virtual ~StageScene();
};

