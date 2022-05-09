#include "GameOver.h"
#include "../Utils/Utils.h"

GameOver::GameOver()
{
}

void GameOver::Init(Vector2i res)
{
	fadeOut.setSize(Vector2f((int)res.x, (int)res.y));
	fadeOut.setFillColor(Color(2, 2, 27));

	sprite.setPosition(-500, -500);

	animation.SetTarget(&sprite);
	animation.AddClip("GameOver");
	animation.AddClip("huge_vfx");

	animation.Play("huge_vfx", true);
	animation.PlayQue("GameOver");
}

bool GameOver::OnGameOver(float dt, Vector2f playerPos)
{
	animation.Update(dt);
	Utils::SetOrigin(sprite, Pivots::Center);
	if (animation.NowPlaying() == "huge_vfx") {
		sprite.setPosition(playerPos);
		return false;
	}
	sprite.setPosition(playerPos.x, playerPos.y - 300);
	return animation.IsAnimationEnd();
}

void GameOver::Draw(RenderWindow& window)
{
	if (animation.NowPlaying() == "GameOver") {
		window.draw(fadeOut);
	}
	window.draw(sprite);
}

GameOver::~GameOver()
{
}
