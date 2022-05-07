#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class stageSceneTrasition {
private:
	const float HEIGHT_MAX = 544.f;
	const int OPACITY_MAX = 255;

	Sprite sprite;
	RectangleShape fadeOut;
	int opacity;
	float height;
	Vector2i resolution;

public:
	stageSceneTrasition();

	void Init(Vector2i res);

	bool OnClear(float dt);

	void Draw(RenderWindow& window);
};