#pragma once
#include "./Scene.h"
#include "../Resource/AnimationController.h"

class EndingCutScene : public Scene
{
private:
	Text textintro;
	Text textintro2;

	Vector2f position;

	Sprite bg;
	Sprite cloud;
	Sprite bu;

	AnimationController animation;
	AnimationClip clip;

	const Vector2i& resolution;
	RenderWindow& window;
	View& mainView;



public:
	EndingCutScene(SceneManager& sceneManager);

	virtual void Init();

	virtual void Update(Time& dt);

	virtual void Render();

	virtual void Release();

	virtual ~EndingCutScene();
};

