#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class FlameBase {
private:
	Sprite sprite;
	Vector2f position;

public:
	FlameBase();

	void Init(float x, float y);

	void Draw(RenderWindow& window);
};