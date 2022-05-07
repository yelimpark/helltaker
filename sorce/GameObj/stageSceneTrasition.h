#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class stageSceneTrasition {
private:
	Sprite sprite;
	RectangleShape bg;
	int opacity;
	float height;
	bool active;
	Vector2i resolution;

public:
	stageSceneTrasition();

	void Init(Vector2i res);

	void Update(float dt);

	void Draw(RenderWindow& window);

	void Avtivate();
};