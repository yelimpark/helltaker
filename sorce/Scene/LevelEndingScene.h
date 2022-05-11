#pragma once
#include "./Scene.h"
#include "../Resource/AnimationController.h"
#include "../GameObj/Death.h"
#include "../GameObj/success.h"
#include "TitleScene.h"
#include <vector>
#include <list>

#define MAX_NUMBER_OF_SCRIPT 4;

class LevelEndingScene : public Scene
{
private:
	//Text textMain;
	Text textFix1;
	Text textFix2[2];
	Text menu[2];

	Death death;
	Success success;

	Sprite hellbackground;

	Sprite menuimg_s1;
	Sprite menuimg_s2;
	
	Texture* texture;
	Texture* menuimag;
	Sprite idle;

	AnimationController animation;
	//std::string script[50];
	Texture *interimg;

	Vector2f position;

	std::vector<Sprite*> flameBases;

	
	Sprite bg;
	Sprite diebg;

	int drawCount;
	int selectIndex;
	int enterCount;

public:
	LevelEndingScene(SceneManager& sceneManager);

	virtual void Init();

	virtual void Update(Time& dt);

	virtual void Render();

	virtual void MoveUp();

	virtual void MoveDown();

	virtual void GoodMenu();

	virtual void badMenu();

	virtual int GetPressedMenu();

	virtual void Release();

	virtual ~LevelEndingScene();

};

