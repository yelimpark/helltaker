#pragma once
#include "./Scene.h"
#include "../Resource/AnimationController.h"
#include "../GameObj/booper.h"
#include "../GameObj/SoundEffect.h"
#include "ChapterSelect.h"


#define MAX_NUMBER_OF_ITEMS 3
class TitleScene : public Scene
{
private:

	ChapterSelect chapterselect;

	Text textFix;
	Text textOpen1[2];
	Text textOpen2[2];
	Text textOpen3;

	booper boo;

	Text menu[MAX_NUMBER_OF_ITEMS];

	Sprite img[MAX_NUMBER_OF_ITEMS];
	Sprite munuwhite[MAX_NUMBER_OF_ITEMS];
	Sprite munured[MAX_NUMBER_OF_ITEMS];

	std::string script[2];
	Vector2f position;

	Sprite bg;
	Sprite beel;

	int selectIndex;
	int enterCount;

	Sprite cloudBackground;

	SoundEffect soundEffects;

public:
	TitleScene(SceneManager& sceneManager);

	virtual void Init();


	virtual void InitMenu();

	virtual void MenuUpdate();

	virtual void Update(Time& dt);

	virtual void MoveUp();

	virtual void MoveDown();

	virtual void MovingMenu();

	virtual void MovingMenuChange();

	virtual void Render();

	virtual int GetPressedMenu();

	virtual void Release();

	virtual ~TitleScene();
};