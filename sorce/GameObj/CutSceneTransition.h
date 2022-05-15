#pragma once
#include <SFML/Graphics.hpp>
#include "../Resource/AnimationController.h"
#include "../GameObj/SoundEffect.h"

class CutSceneTransition
{
private:
	Sprite sprite;
	AnimationController animation;

	SoundEffect soundEffects;

public:
	void Init();
	bool Update(float dt);
	void Draw(RenderWindow& window);

	bool IsFull();
};

