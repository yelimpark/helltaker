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

	float side1SpeedX;
	float side2SpeedX;
	float sideSpeedY;


public:
	static bool isInitUIFontInfo;
	static bool isMovedSide;

	StageUI();
	void Init();
	void Update(int turnTimes);
	void MoveSide(float dt);
	void Render(RenderWindow& window);
	~StageUI();
};

