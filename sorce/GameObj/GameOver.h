#pragma once
#include <SFML/Graphics.hpp>
#include "../Resource/AnimationController.h"
#include "./SoundEffect.h"

using namespace sf;

class GameOver {
private:
	Sprite sprite;
	RectangleShape fadeOut;
	SoundEffect soundEffects;

	AnimationController animation;

public:
	GameOver();

	void Init(Vector2i res);

	bool OnGameOver(float dt, Vector2f playerPos);

	void Draw(RenderWindow& window);

	~GameOver();
};