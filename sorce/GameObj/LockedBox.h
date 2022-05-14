#pragma once
#include <SFML/Graphics.hpp>
#include "Direction.h"
#include "../Resource/AnimationController.h"

using namespace sf;

class LockedBox
{
private:
	Sprite sprite;
	Sprite vfxSprite;
	Vector2f position;
	Vector2f velocity;
	Direction dir;

	float playtime;

	AnimationController vfxAnimation;

	bool isopen;
	bool isEarned;
	bool isActive;

public:
	LockedBox();

	void Init(Vector2f pos);
	void Update(float dt, bool isopen, Vector2f playerpos, int tileSize);
	void Shake(Direction dir);
	void Draw(RenderWindow& window);

	bool IsOpen();
};

