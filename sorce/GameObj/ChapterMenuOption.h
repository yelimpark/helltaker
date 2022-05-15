#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class ChapterMenuOption {
private:
	Sprite outline;
	Sprite inner;
	Sprite number;

	bool active;

public:
	ChapterMenuOption();

	void Init(std::string fileName, Vector2f pos);

	void SetActive(bool active);

	void Draw(RenderWindow& window);

	~ChapterMenuOption();
};