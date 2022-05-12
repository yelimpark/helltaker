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

	float playtime;

	AnimationController vfxAnimation;

	bool isEarned;
	bool isSideShake;
	bool isUpShake;

public:
	void Init(Vector2f pos);
	void Update(float dt);
	void Shake(Direction dir);
	void Draw(RenderWindow& window);
	void Clear();

	bool IsCapturedPlayer(char**& map, int tileSize);
};

