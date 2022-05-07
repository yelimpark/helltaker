#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class StageUI
{
private:
	const float SIDE_WIDTH = 500.f;
	const float SIDE_HEIGHT = 100.f;

	Text turn;
	Text stageNum;

	int lastTurn;

	Sprite sideLeft;
	Sprite sideRight;

	void MoveObj(float x, float y, Transformable& obj);
public:
	StageUI();
	void Init(int lastTurn);
	void UseTurn();
	void OnClear(float dt);
	void Draw(RenderWindow& window);
	~StageUI();

	bool IsGameOver();
};

