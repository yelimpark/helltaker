#pragma once
#include <SFML/Graphics.hpp>
#include "Direction.h"
#include "../SceneInitializer/StageSceneInitializer.h"

using namespace sf;

class Box
{
private:
	Sprite sprite;
	Direction dir;
	Vector2f position;

	bool isMoving;

	float speedX;
	float speedY;



public:
	Box();
	void Init(boxInfo info);
	void Moved(Direction dir);
	void Update(float dt);
	void Draw(RenderWindow& window);
};

