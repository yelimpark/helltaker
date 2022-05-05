#pragma once
#include <SFML/Graphics.hpp>
#include "../Resource/AnimationController.h"
#include "Direction.h"

using namespace sf;

class Player {
private:
	Sprite sprite;
	Vector2f position;
	Direction dir;

	float movetime;
	bool isMoving;

	AnimationController animation;

	void Move(float dt);
public:

	void Init(float x, float y);

	void Update(float dt);

	void Draw(RenderWindow& window);
};