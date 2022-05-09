#pragma once
#include "./Scene.h"
#include "../Utils/SceneManager.h"

using namespace sf;
using namespace std;
#include <map>

#define MAX_NUMBER_OF_MENU 6
class PauseMenu 
{

private:
	Text menuText;

	Text addMenuText[MAX_NUMBER_OF_MENU];

	RectangleShape background;
	RectangleShape container;


	//private functions

public:
	PauseMenu(RenderWindow& window);
	virtual ~PauseMenu();

	//Accessor


	//functions
	void Addbutton();
	void Update();
	void Render(RenderWindow& window); 
};

