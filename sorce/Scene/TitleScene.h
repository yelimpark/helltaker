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
	Sprite cloud;

	Sprite bu;
	Sprite beel;

	int selectIndex;
	int enterCount;

	/*std::string script[50];
	Sprite img[50];*/

	const Vector2i& resolution;
	RenderWindow& window;
	View& mainView;

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