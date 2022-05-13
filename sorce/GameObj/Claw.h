#pragma once
#include <SFML/Graphics.hpp>
#include "../Resource/AnimationController.h"

using namespace sf;

class Claw
{
private:
	Sprite sprite;
	Sprite spriteStop;
	Vector2f position;

	AnimationController animation;

	bool isActive;

public:
	void Init(Vector2f pos, int tileSize);
	void Update(float dt);
	void ActivateClaw(bool isActive);
	void DeactivateClaw();
	void Draw(RenderWindow& window);

	bool IsActive();
	bool IsPlayerInClaw(char**& map, int tileSize);
};

