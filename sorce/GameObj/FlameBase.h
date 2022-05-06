#pragma once
#include <SFML/Graphics.hpp>
#include "../Resource/AnimationController.h"

using namespace sf;

class FlameBase {
private:
	Sprite baseSprite;
	Vector2f position;
	Sprite fireSprite;

	AnimationController animation;

public:
	FlameBase();

	void Init(float x, float y);

	void Update(float dt);

	void Draw(RenderWindow& window);
};