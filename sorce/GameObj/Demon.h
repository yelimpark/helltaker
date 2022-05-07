#pragma once
#include <SFML/Graphics.hpp>
#include "../Resource/AnimationController.h"

using namespace sf;

class Demon
{
private:
	Sprite sprite;
	Sprite heart;
	Vector2f position;
	
	float heartYPos;
	AnimationController animation;
public:
	void Init(Vector2f pos);

	void Update(float dt);
	
	bool IsClear(char**& map, int tileSize);

	void Draw(RenderWindow& window);
};

