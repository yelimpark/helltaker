#pragma once
#include "./Scene.h"
#include "../Resource/AnimationController.h"

class TitleCut : public Scene
{
private:
	Text textintro;
	Text textTop;

	Vector2f position;

	Sprite bg;
	Sprite cloud;
	Sprite beel;
	Sprite bu;

	AnimationController animation;
	AnimationClip clip;

	const Vector2i& resolution;
	RenderWindow& window;
	View& mainView;



public:
	TitleCut(SceneManager& sceneManager);

	virtual void Init();

	virtual void Update(Time& dt);

	virtual void Render();

	virtual void Release();

	virtual ~TitleCut();
};
