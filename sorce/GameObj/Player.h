#pragma once
#include <SFML/Graphics.hpp>
#include "../Resource/AnimationController.h"
#include "Direction.h"

using namespace sf;

class Player {
private:
	const float MOVE_SECOND = 0.2;
	const float MOVE_DURATION = 0.2;
	const float MOVE_DISTANCE = 100;

	Sprite sprite;
	Vector2f position;
	Direction dir;

	float moveTime;
	float moveDuration;
	bool isMoving;

	AnimationController animation;

	void Move(float dt);
public:

	void Init(float x, float y);

	void Update(float dt);

	void Draw(RenderWindow& window);
};