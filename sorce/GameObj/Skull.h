#pragma once
#include <SFML/Graphics.hpp>
#include "Direction.h"
#include "../Resource/AnimationController.h"

using namespace sf;

class Skull
{
private:
	Sprite sprite;
	Vector2f position;
	Direction dir;

	AnimationController animation;

	bool isDead;

public:
	void Init(float x, float y);
	void Update(float dt);
	void OnPushed();
	void OnHitted();
	void Draw(RenderWindow& window);

};

