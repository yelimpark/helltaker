#pragma once
#include <SFML/Graphics.hpp>
#include "../Resource/AnimationController.h"

class CutSceneTransition
{
private:
	Sprite sprite;
	AnimationController animation;

	bool isFull;

public:
	void Init();
	bool Update(float dt);
	void Draw(RenderWindow& window);

	bool IsFull();
};
