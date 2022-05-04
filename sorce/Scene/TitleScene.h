#pragma once
#include "./Scene.h"
#include "../Resource/AnimationController.h"


#define MAX_NUMBER_OF_ITEMS 3
class TitleScene : public Scene 
{
private:
	Text textintro;
	Text textOpen[2];


	Sprite img[MAX_NUMBER_OF_ITEMS];
	

	Text menu[MAX_NUMBER_OF_ITEMS];
	Sprite munuwhite[MAX_NUMBER_OF_ITEMS];
	Sprite munured[MAX_NUMBER_OF_ITEMS];

	Vector2f position;

	Sprite bg;
	Sprite cloud[3];
	float speed;
	float cloudTimer;
	Vector2f cloudPosition[3];

	Sprite bu;
	Sprite beel;

	int selectIndex;
	int enterCount;

	const Vector2i& resolution;
	RenderWindow& window;
	View& mainView;

	Sprite testSprite;

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