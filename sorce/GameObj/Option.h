#pragma once
#include <SFML/Graphics.hpp>
#include "../SceneInitializer/LevelEndingSceneInitializer.h"

using namespace sf;

class Option {
private:
	Sprite sprite;
	Text text;
	bool isBad;
	bool active;

public:
	Option();

	void Init(OptionData& data, Vector2f pos);

	void SetActive(bool active);

	void Draw(RenderWindow& window);

	bool IsBad();
};