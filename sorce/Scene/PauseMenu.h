#pragma once
#include "./Scene.h"
#include "../Utils/SceneManager.h"
#include "../GameObj/SoundType.h"


using namespace sf;
using namespace std;
#include <map>

class SoundType;

#define MAX_NUMBER_OF_MENU 5

class PauseMenu
{
private:

	SoundType soundtype;

	Text menuText;

	Text addMenuText[MAX_NUMBER_OF_MENU];

	RectangleShape background;
	RectangleShape container;

	SceneManager& sceneManager;

	Sprite img[MAX_NUMBER_OF_MENU];
	Sprite circle[2];
	Sprite menuline;

	int selectIndex;

public:

	PauseMenu(RenderWindow& window, SceneManager& sceneManager);

	virtual ~PauseMenu();

	virtual void ContainerInit(RenderWindow& window);

	virtual void UpInit();

	virtual void CircleInit();

	virtual void InputButton();
	virtual int GetPressedMenu();

	virtual void MovingMenu();
	virtual void MovingMenuChange();
	virtual void MoveUp();
	virtual void MoveDown();


	//Functions
	virtual void Update();
	virtual void Render(RenderWindow& window);



};