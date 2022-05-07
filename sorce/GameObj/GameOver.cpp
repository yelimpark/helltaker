#include "GameOver.h"
#include "../Utils/Utils.h"

GameOver::GameOver()
{
}

void GameOver::Init(Vector2i res)
{
	fadeOut.setSize(Vector2f((int)res.x, (int)res.y));
	fadeOut.setFillColor(Color::Black);

	animation.SetTarget(&sprite);
	animation.AddClip("GameOver");
	animation.Play("GameOver");
}

bool GameOver::OnGameOver(float dt, Vector2f playerPos)
{
	sprite.setPosition(playerPos.x - 450, playerPos.y - 950);
	animation.Update(dt);
	return animation.IsAnimationEnd();
}

void GameOver::Draw(RenderWindow& window)
{
	window.draw(fadeOut);
	window.draw(sprite);
}

GameOver::~GameOver()
{
}
