#pragma once
#include <SFML/Graphics.hpp>
#include "../Resource/AnimationController.h"
#include "./GetVfx.h"

using namespace sf;

class Key
{
private:
	Sprite sprite;
	Sprite vfxSprite;
	Vector2f position;

	GetVfx getVfx;
	AnimationController vfxAnimation;

	AnimationController animation;

	bool isEarned;

public:
	void Init(Vector2f pos, int tileSize);
	void Update(float dt);
	void Draw(RenderWindow& window);
	void Clear();

	bool IsCapturedPlayer(char**& map, int tileSize);

	Vector2f GetKeyPos();
};

