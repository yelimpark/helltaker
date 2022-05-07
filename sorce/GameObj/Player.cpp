#include "Player.h"
#include "../Utils/InputManager.h"
#include "../Utils/Utils.h"
#include "./Box.h"
#include "./MapCode.h"

#include <iostream>

void Player::Init(Vector2f pos, int tileSize, float moveSecond)
{
	position = pos;
	sprite.setPosition(position);

	animation.SetTarget(&sprite);

	animation.AddClip("PlayerStand");
	animation.AddClip("PlayerMove");
	animation.AddClip("PlayerKick");

	animation.Play("PlayerStand");

	moveDistance = tileSize;
	this->moveSecond = moveSecond;
	moveTime = moveSecond + MOVE_DURATION;
	dir = Direction::None;
}

void Player::Move(float dt)
{
	moveTime -= dt;

	if (moveTime <= MOVE_DURATION) {
		if (moveTime <= 0) {
			moveTime = moveSecond + MOVE_DURATION;
			position = nextPosition;
			sprite.setPosition(position);
			dir = Direction::None;
		}
		//return;
	}

	position += (nextPosition - prevPosition) * dt / (moveSecond + MOVE_DURATION);

	sprite.setPosition(position);
}

void Player::Kick()
{
	animation.Play("PlayerKick");
	animation.PlayQue("PlayerStand");
}

void Player::HanddleInput(char ** &map, std::vector<Box*>& boxes)
{
	if (animation.NowPlaying() != "PlayerStand" || dir != Direction::None) return;

	if (InputManager::GetKey(Keyboard::Left)) {
		sprite.setScale(-1.f, 1.f);
		nextPosition.x = position.x - moveDistance;
		nextPosition.y = position.y;
		dir = Direction::Left;
	}
	if (InputManager::GetKey(Keyboard::Right)) {
		sprite.setScale(1.f, 1.f);
		nextPosition.x = position.x + moveDistance;
		nextPosition.y = position.y;
		dir = Direction::Right;
	}
	if (InputManager::GetKey(Keyboard::Up)) {
		nextPosition.x = position.x;
		nextPosition.y = position.y - moveDistance;
		dir = Direction::Up;
	}
	if (InputManager::GetKey(Keyboard::Down)) {
		nextPosition.x = position.x;
		nextPosition.y = position.y + moveDistance;
		dir = Direction::Down;
	}

	if (dir != Direction::None) {
		switch (map[(int)nextPosition.y / 100][(int)nextPosition.x / 100]) {
		case (char)MapCode::WALL:
			dir = Direction::None;
			return;

		case (char)MapCode::BOX:
			for(auto& box : boxes) {
				if (box->IsBoxHere(nextPosition)) {
					box->Move(dir, map);
				}
			}
			Kick();
			dir = Direction::None;
			return;

		default:
			break;
		}

		map[(int)nextPosition.y / 100][(int)nextPosition.x / 100] = 'P';
		map[(int)position.y / 100][(int)position.x / 100] = 'E';
		prevPosition = position;
		animation.Play("PlayerMove");
		animation.PlayQue("PlayerStand");
	}
}

void Player::Update(float dt)
{
	if (dir != Direction::None) Move(dt);

	animation.Update(dt);
	Utils::SetOrigin(sprite, Pivots::Center);
}

void Player::Draw(RenderWindow& window)
{
	window.draw(sprite);
}
