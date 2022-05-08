#pragma once
#include <SFML/Graphics.hpp>
#include "../Resource/AnimationController.h"
#include "./Direction.h"
#include "../GameObj/SoundEffect.h"

using namespace sf;

class Box;

class Player {
private:
	float moveSecond;
	float MOVE_DURATION = 0.2;
	int tileSize;

	Sprite sprite;
	Vector2f position;

	Vector2f nextPosition;
	Vector2f prevPosition;
	float moveTime;
	Direction dir;

	AnimationController animation;

	SoundEffect soundEffects;

	void Move(float dt);

	void Kick();

public:

	void Init(Vector2f pos, int tileSize, float moveSecond);

	void Update(float dt);

	void HanddleInput(char**& map, std::vector<Box*> &boxes);

	void Draw(RenderWindow& window);

	const Vector2f GetPos();
};