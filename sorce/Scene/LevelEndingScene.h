#pragma once
#include "./Scene.h"
#include "../Resource/AnimationController.h"
#include "TitleScene.h"

#define MAX_NUMBER_OF_SCRIPT 2
class LevelEndingScene : public Scene
{
private:
	//Text textMain;
	Text textFix1;
	Text textFix2[2];
	Text menu[2];

	Sprite hellbackground;

	Sprite img[2];
	Texture* texture;
	Sprite idle;

	//std::string script[50];
	Texture *interimg;

	Vector2f position;
	
	Sprite bg;


	int selectIndex;
	int enterCount;


	const Vector2i& resolution;
	RenderWindow& window;
	View& mainView;
	

public:
	LevelEndingScene(SceneManager& sceneManager);

	virtual void Init();

	virtual void Update(Time& dt);

	virtual void Render();

	virtual void MoveUp();

	virtual void MoveDown();

	virtual int GetPressedMenu();

	virtual void Release();

	virtual ~LevelEndingScene();

};

