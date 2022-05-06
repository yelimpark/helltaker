#include "Player.h"
#include "../Utils/InputManager.h"

void Player::Move(float dt)
{
	moveTime -= dt;

	if (moveTime <= 0) {
		moveDuration -= dt;
		if (moveDuration <= 0) {
			moveDuration = MOVE_DURATION;
			moveTime = MOVE_SECOND;
			isMoving = false;
		}
		return;
	}

	switch (dir)
	{
	case Direction::Left:
		position.x -= MOVE_DISTANCE * dt / MOVE_SECOND;
		break;
	case Direction::Right:
		position.x += MOVE_DISTANCE * dt / MOVE_SECOND;
		break;
	case Direction::Down:
		position.y += MOVE_DISTANCE * dt / MOVE_SECOND;
		break;
	case Direction::Up:
		position.y -= MOVE_DISTANCE * dt / MOVE_SECOND;
		break;
	case Direction::None:
		break;
	default:
		break;
	}
	sprite.setPosition(position);
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

	moveTime = MOVE_SECOND;
	moveDuration = MOVE_DURATION;
	isMoving = false;
}

void Player::Update(float dt)
{
	if (isMoving) Move(dt);

	animation.Update(dt);


	if (!isMoving && InputManager::GetKey(Keyboard::Left)) {
		isMoving = true;
		dir = Direction::Left;
		sprite.setScale(-1.f, 1.f);
		animation.Play("PlayerMove");
		animation.PlayQue("PlayerStand");
	}
	if (!isMoving && InputManager::GetKey(Keyboard::Right)) {
		isMoving = true;
		dir = Direction::Right;
		sprite.setScale(1.f, 1.f);
		animation.Play("PlayerMove");
		animation.PlayQue("PlayerStand");
	}
	if (!isMoving && InputManager::GetKey(Keyboard::Up)) {
		isMoving = true;
		dir = Direction::Up;
		animation.Play("PlayerMove");
		animation.PlayQue("PlayerStand");
	}
	if (!isMoving && InputManager::GetKey(Keyboard::Down)) {
		isMoving = true;
		dir = Direction::Down;
		animation.Play("PlayerMove");
		animation.PlayQue("PlayerStand");
	}
}

void Player::Draw(RenderWindow& window)
{
	window.draw(sprite);
}
