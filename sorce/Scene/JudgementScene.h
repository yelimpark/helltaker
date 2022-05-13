#pragma once
#include "./Scene.h"
#include <SFML/Graphics.hpp>
#include "../Resource/AnimationController.h"

using namespace sf;

class JudgementScene : public Scene {
private:
	const float speedY = 250;
	
	RectangleShape bgColor;

	Sprite sinGearsL;
	Sprite sinGearsR;
	AnimationController sinGearsLAC;
	AnimationController sinGearsRAC;

	Sprite bridge;

	Sprite sinPanelL;
	Sprite sinPanelR;
	Sprite sinPyre[4];
	Sprite sinEye;
	Sprite sinWheel;

public:
	JudgementScene(SceneManager& sceneManager);

	virtual void Init();

	virtual void Update(Time& dt);

	virtual void Render();

	virtual void Release();

	virtual ~JudgementScene();
};