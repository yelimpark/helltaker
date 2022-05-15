#pragma once
#include "../GameObj/Option.h"
#include "../Utils/SceneManager.h"

class MainMenu {
private:
	Text name;
	Option options[3];
	const int OPTION_COUNT = 3;
	int cursor;

public:
	MainMenu();

	void Init(Vector2i resolution);

	bool HandleInput(RenderWindow& window, SceneManager& sm);

	void Draw(RenderWindow& window);

	~MainMenu();
};