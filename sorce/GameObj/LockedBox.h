#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class LockedBox
{
private:
	Sprite sprite;
	Vector2f position;

public:
	void Init(Vector2f pos);
	void Update();
	void Draw(RenderWindow& window);
};

