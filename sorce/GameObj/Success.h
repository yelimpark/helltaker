
#pragma once
#include "../Resource/AnimationController.h"
#include <SFML/Graphics.hpp>
#include <math.h>
#include "../GameObj/SoundEffect.h"

using namespace sf;

class Success
{
private:
	Sprite sprite;
	AnimationController animation;

	SoundEffect soundEffects;

public:
	Success();
	void Init(Vector2f pos);
	void Update(float dt);
	void Draw(RenderWindow& window);
	~Success();
};


