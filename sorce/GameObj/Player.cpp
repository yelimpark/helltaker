#include "Player.h"
#include "../Utils/InputManager.h"

#include <iostream>

void Player::Move(float dt)
{
	moveTime -= dt;

	if (moveTime <= MOVE_DURATION) {
		if (moveTime <= 0) {
			moveTime = MOVE_SECOND + MOVE_DURATION;
			position = nextPosition;
			sprite.setPosition(position);
			isMoving = false;
		}
		//return;
	}

	position += (nextPosition - prevPosition) * dt / (MOVE_SECOND + MOVE_DURATION);

	sprite.setPosition(position);
}

void Player::Kick()
{
	animation.Play("PlayerKick");
	animation.PlayQue("PlayerStand");
}

void Player::HanddleInput(char ** &map)
{
	if (animation.NowPlaying() != "PlayerStand") return;

	bool isMoveTriggered = false;

	if (!isMoving && InputManager::GetKey(Keyboard::Left)) {
		isMoveTriggered = true;
		sprite.setScale(-1.f, 1.f);
		nextPosition.x = position.x - MOVE_DISTANCE;
		nextPosition.y = position.y;
	}
	if (!isMoving && InputManager::GetKey(Keyboard::Right)) {
		isMoveTriggered = true;
		sprite.setScale(1.f, 1.f);
		nextPosition.x = position.x + MOVE_DISTANCE;
		nextPosition.y = position.y;
	}
	if (!isMoving && InputManager::GetKey(Keyboard::Up)) {
		isMoveTriggered = true;
		nextPosition.x = position.x;
		nextPosition.y = position.y - MOVE_DISTANCE;
	}
	if (!isMoving && InputManager::GetKey(Keyboard::Down)) {
		isMoveTriggered = true;
		nextPosition.x = position.x;
		nextPosition.y = position.y + MOVE_DISTANCE;
	}

	if (isMoveTriggered) {
		switch (map[(int)nextPosition.y / 100][(int)nextPosition.x / 100]) {
		case 'W':
			isMoveTriggered = false;
			return;

		case 'B':
			isMoveTriggered = false;
			Kick();
			return;

		default:
			break;
		}

		map[(int)nextPosition.y / 100][(int)nextPosition.x / 100] = 'P';
		map[(int)position.y / 100][(int)position.x / 100] = 'E';
		prevPosition = position;
		isMoving = true;
		animation.Play("PlayerMove");
		animation.PlayQue("PlayerStand");
	}
}

void Player::Init(float x, float y, int tileSize)
{
	position.x = x;
	position.y = y;

	sprite.setPosition(position);
	
	animation.SetTarget(&sprite);

	animation.AddClip("PlayerStand");
	animation.AddClip("PlayerMove");
	animation.AddClip("PlayerKick");

	animation.Play("PlayerStand");

	MOVE_DISTANCE = tileSize;

	moveTime = MOVE_SECOND + MOVE_DURATION;
}

void Player::Update(float dt)
{
	if (isMoving) Move(dt);

	animation.Update(dt);
	sprite.setOrigin(sprite.getGlobalBounds().width * 0.5f, sprite.getGlobalBounds().height * 0.5f);
}

void Player::Draw(RenderWindow& window)
{
	window.draw(sprite);
}
