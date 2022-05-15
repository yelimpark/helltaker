#pragma once
#include <SFML/Graphics.hpp>
#include "../Resource/AnimationController.h"

using namespace sf;

class Demon
{
private:
	Sprite sprite;
	Vector2f position;
	AnimationController animation;

	Sprite heart;
	float heartYPos;	
	float heartDir;
	bool isheartmoving;

public:
	void Init(Vector2f pos, std::string demonName);

	void Update(float dt);
	
	bool IsClear(char**& map, int tileSize);

	void Draw(RenderWindow& window);
};

