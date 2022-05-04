#pragma once
#include "./Scene.h"
#include "../Resource/AnimationController.h"

class TitleScriptScene : public Scene
{
private:
	Text textintro;
	

	Vector2f position;

	Sprite bg;
	Sprite bu;

	std::string script[50];
	Sprite* img;
	Sprite imgMenu;

	const Vector2i& resolution;
	RenderWindow& window;
	View& mainView;

	int textselectIndex;
	int enterCounter;

public:
	TitleScriptScene(SceneManager& sceneManager);

	virtual void Init();

	virtual void Update(Time& dt);

	virtual void Render();

	virtual void Release();

	virtual ~TitleScriptScene();
};

