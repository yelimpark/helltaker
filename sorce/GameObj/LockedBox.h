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

	AnimationController vfxAnimation;

	bool isEarned;

public:
	void Init(Vector2f pos);
	void Update(float dt);
	void Draw(RenderWindow& window);
	void Clear();

	bool IsCapturedPlayer(char**& map, int tileSize);
};

