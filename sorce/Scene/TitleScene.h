#pragma once
#include "./Scene.h"
#include "../Resource/AnimationController.h"

class TitleScene : public Scene 
{
private:
	Text textintro;

	Vector2f position;

	Sprite bg;
	Sprite bu;

	AnimationController animation;
	AnimationClip clip;

	const Vector2i& resolution;
	RenderWindow& window;
	View& mainView;

	

public:
	TitleScene(SceneManager& sceneManager);

	virtual void Init();

	virtual void Update(Time& dt);

	virtual void Render();

	virtual void Release();

	virtual ~TitleScene();
};