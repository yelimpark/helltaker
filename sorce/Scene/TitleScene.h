#pragma once
#include "./Scene.h"
#include "../Resource/AnimationController.h"
#include "../GameObj/SoundEffect.h"

#define MAX_NUMBER_OF_ITEMS 3
class TitleScene : public Scene 
{
private:
	Text textFix;
	Text textOpen1[2];
	Text textOpen2[2];
	Text textOpen3;
	
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

	virtual void Update(Time& dt);

	virtual void Render();

	virtual void MoveUp();

	virtual void MoveDown();

	virtual int GetPressedMenu();

	virtual void Release();

	virtual ~TitleScene();
};