#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

enum class Direction
{
	Left,
	Right,
	Up,
	Down,
};

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

