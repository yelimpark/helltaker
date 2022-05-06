#pragma once
#include <SFML/Graphics.hpp>
#include "../Resource/AnimationController.h"
#include "Direction.h"

using namespace sf;

class Player {
private:
	const float MOVE_SECOND = 0.2;
	const float MOVE_DURATION = 0.2;
	float MOVE_DISTANCE;

	Sprite sprite;
	Vector2f position;

	Vector2f nextPosition;
	Vector2f prevPosition;
	float moveTime;
	bool isMoving;

	AnimationController animation;

	void Move(float dt);

	void Kick();

public:

	void Init(Vector2f pos, int tileSize);

	void Update(float dt);

	void HanddleInput(char**& map);

	void Draw(RenderWindow& window);
};