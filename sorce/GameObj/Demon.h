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
	void Init(float x, float y);
	void Update(float dt);
	void Draw(RenderWindow& window);

};

