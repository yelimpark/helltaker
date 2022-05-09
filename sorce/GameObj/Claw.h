#pragma once
#include <SFML/Graphics.hpp>
#include "../Resource/AnimationController.h"

using namespace sf;

class Claw
{
private:
	Sprite sprite;
	Vector2f position;

	AnimationController animation;

	bool isActive;

public:
	void Init();
	void Update(float dt);
	void ActivateClaw();
	void DeactivateClaw();
	void Draw(RenderWindow& window);

	bool IsActive();
};

