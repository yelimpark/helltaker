#pragma once
#include <SFML/Graphics.hpp>
#include "../Resource/AnimationController.h"

using namespace sf;

class Key
{
private:
	Sprite sprite;
	Vector2f position;

	AnimationController animation;

public:
	void Init(Vector2f pos, int tileSize);
	void Update(float dt);
	void Draw(RenderWindow& window);
	void Clear();

	bool IsCapturedPlayer(char**& map, int tileSize);

};

