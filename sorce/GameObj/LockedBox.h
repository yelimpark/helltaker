#pragma once
#include <SFML/Graphics.hpp>
#include "Direction.h"

using namespace sf;

class LockedBox
{
private:
	Sprite sprite;
	Vector2f position;

	bool isEarned;

public:
	void Init(Vector2f pos);
	void Update();
	void Draw(RenderWindow& window);
	void Clear();

	bool IsCapturedPlayer(char**& map, int tileSize);
};

