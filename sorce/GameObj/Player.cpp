#include "Player.h"
#include "../Utils/InputManager.h"

void Player::Move(float dt)
{
	movetime -= dt;

	switch (dir)
	{
	case Direction::Left:
		position.x -= (500 * movetime) * dt;
		break;
	case Direction::Right:
		position.x += (500 * movetime) * dt;
		break;
	case Direction::Down:
		break;
	case Direction::Up:
		break;
	case Direction::None:
		break;
	default:
		break;
	}
	sprite.setPosition(position);

	if (movetime <= 0) {
		movetime = 0.5f;
		isMoving = false;
	}
}

void Player::Init(float x, float y)
{
	position.x = x;
	position.y = y;

	sprite.setPosition(position);
	animation.SetTarget(&sprite);

	animation.AddClip("PlayerStand");
	animation.AddClip("PlayerMove");

	animation.Play("PlayerStand");

	movetime = 0.5f;
	isMoving = false;
}

void Player::Update(float dt)
{
	if (isMoving) {
		Move(dt);
	}

	animation.Update(dt);
	sprite.setOrigin(sprite.getGlobalBounds().width * 0.5f, sprite.getGlobalBounds().height * 0.5f);

	if (InputManager::GetKeyDown(Keyboard::Left) || InputManager::GetKey(Keyboard::Left)) {
		isMoving = true;
		dir = Direction::Left;
		sprite.setScale(-1.f, 1.f);
		animation.Play("PlayerMove");
		animation.changePlayTime(0.5);
		animation.PlayQue("PlayerStand");
	}
	if (InputManager::GetKeyDown(Keyboard::Right)) {
		isMoving = true;
		dir = Direction::Right;
		sprite.setScale(1.f, 1.f);
		animation.Play("PlayerMove");
		animation.PlayQue("PlayerStand");
	}
}

void Player::Draw(RenderWindow& window)
{
	window.draw(sprite);
}
