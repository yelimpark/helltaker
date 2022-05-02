#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class StageUI
{
private:
	Text turn;
	Text stageNum;

	Sprite side1;
	Sprite side2;

	static bool isInitUIFontInfo;

public:
	StageUI();
	void Update(int turnTimes, Vector2i position);
	void Draw(RenderWindow& window);
};

