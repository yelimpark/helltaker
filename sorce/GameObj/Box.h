#pragma once
#include <SFML/Graphics.hpp>
#include "Direction.h"
#include "../SceneInitializer/StageSceneInitializer.h"

using namespace sf;

class Box
{
private:
	float moveSecond;
	int moveDistance;

	Sprite sprite;
	Vector2f position;

	Vector2f nextPosition;
	Direction dir;
	float moveTime;
	float playTime;

	Direction shakeDir;

public:
	Box();
	void Init(BoxData info, int tileSize, float moveSecond);
	bool Move(Direction dir, char**& map);
	void Update(float dt);
	void Draw(RenderWindow& window);

	const Vector2f& GetPos();
	const bool IsBoxHere(Vector2f pos);
};

