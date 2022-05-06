#pragma once
#include <SFML/Graphics.hpp>
#include "Direction.h"
#include "../SceneInitializer/StageSceneInitializer.h"

using namespace sf;

class Box
{
private:
	const float MOVE_SECOND = 0.2;
	float MOVE_DISTANCE;

	Sprite sprite;
	Direction dir;
	Vector2f position;

	bool isMoving;

	float moveTime;

public:
	Box();
	void Init(BoxData info, int tileSize);
	void Moved(Direction dir);
	void Update(float dt);
	void Draw(RenderWindow& window);

	const Vector2f& GetPos();
	const bool IsBoxHere(Vector2f pos);
};

