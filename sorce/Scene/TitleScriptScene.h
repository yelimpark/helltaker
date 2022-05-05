#pragma once
#include "./Scene.h"
#include "../Resource/AnimationController.h"

#define MAX_NUMBER_OF_SCRIPT 9

class TitleScriptScene : public Scene
{
private:
	Text textintro;
	

	Vector2f position;

	Sprite bg;
	Sprite cloudBackground;
	Sprite beelFire;

	std::string script[MAX_NUMBER_OF_SCRIPT];
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

