#pragma once
#include <SFML/Graphics.hpp>
#include "Direction.h"

using namespace sf;

class Box
{
private:
	Sprite box;
	Direction dir;
	bool isMoving;

	float speedX;
	float speedY;



public:
	Box();
	void Init();
	void Moved(Direction dir);
	void Update(float dt);
	void Draw(RenderWindow& window);
};

