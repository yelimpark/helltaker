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

public:
	void Init(float x, float y);
	void Update(float dt);
	void Draw(RenderWindow& window);

};

