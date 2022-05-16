#pragma once
#include <SFML/Graphics.hpp>
#include "../Resource/AnimationController.h"
#include "./SoundEffect.h"

using namespace sf;

class GetVfx
{
private:
	Sprite sprite;
	Vector2f position;

	AnimationController animation;
	SoundEffect soundEffects;

public:
	void Init(Vector2f keyPos);
	void Update(float dt);
	void Draw(RenderWindow& window);
};

