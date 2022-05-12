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

	Direction dir;
	float moveTime;
	float playTime;

	bool isSideShake;
	bool isUpShake;

public:
	Box();
	void Init(BoxData info, int tileSize, float moveSecond);
	bool Move(Direction dir, char**& map);
	void Shake(Direction dir);
	void Update(float dt);
	void Draw(RenderWindow& window);
	const Vector2f& GetPos();
	const bool IsBoxHere(Vector2f pos);

};

