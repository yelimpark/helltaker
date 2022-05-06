#pragma once
#include <SFML/Graphics.hpp>
#include "Direction.h"
#include "../SceneInitializer/StageSceneInitializer.h"

using namespace sf;

class Box
{
private:
	const float MOVE_SECOND = 0.2;
	const float MOVE_DISTANCE = 100;

	Sprite sprite;
	Direction dir;
	Vector2f position;

	bool isMoving;

	float speedX;
	float speedY;

	float moveTime;

public:
	Box();
	void Init(boxInfo info);
	void Moved(float dt);
	void Update(float dt);
	void Draw(RenderWindow& window);
};

