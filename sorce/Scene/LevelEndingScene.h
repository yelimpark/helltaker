#pragma once
#include "./Scene.h"
#include "../Resource/AnimationController.h"
#include "TitleScene.h"
#include "../GameObj/SoundEffect.h"

#define MAX_NUMBER_OF_ITEMS 2
class LevelEndingScene : public Scene
{
private:
	//Text textMain;
	Text textFix1;
	Text textFix2[2];
	Text menu[2];

	Sprite hellbackground;

	Sprite img[2];
	Sprite idle[2];

	//std::string script[50];
	Texture *interimg;

	Vector2f position;
	
	Sprite bg;

	SoundEffect soundEffects;

	int selectIndex;
	int enterCount;

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

