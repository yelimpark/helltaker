#pragma once
#include "./Scene.h"
#include "../Resource/AnimationController.h"

class TitleScriptScene : public Scene
{
private:
	Text textintro;
	Text textTop;

	Vector2f position;

	Sprite bg;
	Sprite bu;

	const Vector2i& resolution;
	RenderWindow& window;
	View& mainView;



public:
	TitleScriptScene(SceneManager& sceneManager);

	virtual void Init();

	virtual void Update(Time& dt);

	virtual void Render();

	virtual void Release();

	virtual ~TitleScriptScene();
};

