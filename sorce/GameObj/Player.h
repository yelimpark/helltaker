#pragma once
#include <SFML/Graphics.hpp>
#include "../Resource/AnimationController.h"
#include "./Direction.h"
#include "./MoveVfx.h"
#include "./KickVfx.h"
#include "../GameObj/SoundEffect.h"

using namespace sf;

class Box;
class Skull;
class Key;
class LockedBox;

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

	MoveVfx moveVfx;
	KickVfx kickVfx;

	SoundEffect soundEffects;

	void Move(float dt);

	void Kick(bool isItMove);

public:
	Player();

	void Init(Vector2f pos, int tileSize, float moveSecond);

	void Update(float dt);

	bool HanddleInput(char**& map, std::vector<Box*> &boxes, std::vector<Skull*>& skulls, LockedBox &lockedbox);

	void Draw(RenderWindow& window);

	Vector2f GetPos();
};