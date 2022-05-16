#pragma once
#include <SFML/Graphics.hpp>
#include "../Resource/AnimationController.h"

using namespace sf;

class MoveVfx {
private:
	Sprite sprite;
	AnimationController animation;

public:
	MoveVfx();

	void Init(Vector2f pos);

	void Update(float dt);

	void Draw(RenderWindow& window);
};