#pragma once
#include <SFML/Graphics.hpp>
#include "../Resource/AnimationController.h"

using namespace sf;

class BloodVfx
{
private:
	Sprite sprite;
	AnimationController animation;

public:
	BloodVfx();
	void Init(Vector2f playerPos);
	void Update(float dt);
	void Draw(RenderWindow& window);
	~BloodVfx();
};

