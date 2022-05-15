#pragma once
#include <SFML/Graphics.hpp>
#include "../Resource/AnimationController.h"
#include "Skull.h"
#include "Player.h"

class Player;
class Skull;

using namespace sf;

class Claw
{
private:
	Sprite sprite;
	Vector2f position;

	AnimationController animation;

	bool isActive;

public:
	void Init(Vector2f pos);
	bool Update(float dt, std::vector<Skull*>& skulls, Player& player);
	void Draw(RenderWindow& window);
};

