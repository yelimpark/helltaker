#pragma once
#include <SFML/Graphics.hpp>
#include "../Resource/AnimationController.h"
#include "./GetVfx.h"
#include "./SoundEffect.h"

using namespace sf;

class Key
{
private:
	Sprite sprite;
	Sprite vfxSprite;
	Vector2f position;

	AnimationController vfxAnimation;
	AnimationController animation;
	SoundEffect soundEffects;

	bool isEarned;
	bool isActive;

public:
	Key();

	void Init(Vector2f pos);
	void Update(float dt, Vector2f playerpos, int tileSize);
	void Draw(RenderWindow& window);

	bool IsCapturedPlayer();
};

