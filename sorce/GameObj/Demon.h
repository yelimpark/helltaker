#pragma once
#include <SFML/Graphics.hpp>
#include "../Resource/AnimationController.h"

using namespace sf;

class Demon
{
private:
	Sprite sprite;
	Vector2f position;
	AnimationController animation;

	Sprite heart;
	float heartYPos;	
	float dir = 1.f;
	bool isheartmoving = false;

public:
	void Init(Vector2f pos);

	void Update(float dt);
	
	bool IsClear(char**& map, int tileSize);

	void Draw(RenderWindow& window);
};

