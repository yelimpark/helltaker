#pragma once
#include <SFML/Graphics.hpp>
#include "Direction.h"
#include "../Resource/AnimationController.h"
#include "../SceneInitializer/StageSceneInitializer.h"

using namespace sf;

class Skull
{
private:
	float moveSecond;
	float moveTime;
	int moveDistance;
	int tileSize;

	Sprite sprite;
	Vector2f position;
	Direction dir;

	AnimationController animation;

	bool isDead;

public:
	void Init(SkullData info, int tileSize, float moveSecond);
	void Update(float dt, char**& map);
	void OnPushed(Direction dir, char**& map);
	void OnHitted();
	void Draw(RenderWindow& window);

	const Vector2f& GetPos();
	const bool IsSkullHere(Vector2f pos);

};

