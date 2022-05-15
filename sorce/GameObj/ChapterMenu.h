#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "../GameObj/ChapterMenuOption.h"
#include "../GameObj/SoundEffect.h"
#include "../Utils/SceneManager.h"

using namespace sf;

class ChapterMenu {
private:
	Text text;
	std::vector<ChapterMenuOption * > options;
	std::vector<std::string> chapters;
	Sprite topOutline;
	Sprite bottomOutline;
	int cursor;
	SoundEffect soundEffects;

public:
	ChapterMenu();

	void Init(Vector2i resolution);

	void HandleInput(SceneManager& sm);

	void Draw(RenderWindow& window);

	void Release();

	~ChapterMenu();
};