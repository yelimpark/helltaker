#pragma once
#include <SFML/Graphics.hpp>
#include "../Resource/AnimationController.h"

class CutSceneTransition
{
private:
	Sprite sprite;
	Vector2f position;
	AnimationController animation;

public:
	void Init();
	void Update(float dt);
	void Draw(RenderWindow& window);
};

