#pragma once
#include "./Scene.h"
#include "../Resource/AnimationController.h"

#define MAX_NUMBER_OF_ITEMS 3

class TitleCutMenu : public Scene
{
private:
	Text textTop;
	Text menu[MAX_NUMBER_OF_ITEMS];

	Vector2f position;

	Sprite bg;
	Sprite cloud;
	Sprite beel;
	Sprite munuwhite[MAX_NUMBER_OF_ITEMS];
	Sprite munured[MAX_NUMBER_OF_ITEMS];
	int selectIndex;


	AnimationController animation;
	AnimationClip clip;

	const Vector2i& resolution;
	RenderWindow& window;
	View& mainView;



public:
	TitleCutMenu(SceneManager& sceneManager);

	virtual void Init();

	virtual void Update(Time& dt);

	virtual void Render();

	virtual void MoveUp();

	virtual void MoveDown();

	virtual int GetPressedMenu();

	virtual void Release();

	virtual ~TitleCutMenu();
};