#pragma once
#include "../Resource/AnimationController.h"
#include <SFML/Graphics.hpp>
#include <math.h>

using namespace sf;

class Death
{
private:
	Sprite sprite;
	AnimationController animation;

public:
	Death();
	void Init(Vector2f pos);
	void Update(float dt);
	void Draw(RenderWindow& window);
	~Death();
};

