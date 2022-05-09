#pragma once
#include <SFML/Graphics.hpp>
#include "../Resource/AnimationController.h"

using namespace sf;

class booper
{
private:
	Sprite sprite;
	AnimationController animation;

public:
	booper();
	void Update(float dt);
	void Init(Vector2f pos);
	void Draw(RenderWindow& window);
	~booper();
};

