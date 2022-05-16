#pragma once
#include <SFML/Graphics.hpp>
#include "../SceneInitializer/CutSceneInitializer.h"

using namespace sf;

class Option {
private:
	Sprite sprite;
	Text text;
	bool active;
	std::string nextNode;

public:
	Option();

	void Init(OptionData& data, Vector2f pos);

	void SetActive(bool active);

	void Draw(RenderWindow& window);

	bool IsActive();

	std::string& GetNextNode();
};