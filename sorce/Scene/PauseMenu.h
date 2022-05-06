#pragma once
#include "./Scene.h"
#include "../Utils/SceneManager.h"

using namespace sf;
using namespace std;
#include <map>

class PauseMenu 
{

private:
	Text menuText;

	RectangleShape background;
	RectangleShape container;
	//RectangleShape button;

public:
	PauseMenu(RenderWindow& window);
	virtual ~PauseMenu();

	//functions
	void Update();
	void Render(RenderWindow& window); 
};

