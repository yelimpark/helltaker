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
	int moveDistance;

	Sprite sprite;
	Vector2f position;
	AnimationController animation;
	
	Direction dir;
	float moveTime;

	bool isDead;

public:
	bool IsMoving() { return dir != Direction::None; }
	void Init(Vector2f pos, int tileSize, float moveSecond);
	void Update(float dt);
	void OnPushed(Direction dir, char**& map);
	void Draw(RenderWindow& window);

	const Vector2f& GetPos();
	const bool IsSkullHere(Vector2f pos);
	const bool IsDead();
};

