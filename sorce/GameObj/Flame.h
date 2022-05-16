#pragma once
#include <SFML/Graphics.hpp>
#include "../Resource/AnimationController.h"

using namespace sf;

class Flame {
private:
	Sprite sprite;
	AnimationController animation;

public:
	Flame();

	void Init(Vector2f pos);

	void Update(float dt);

	void Draw(RenderWindow& window);
};