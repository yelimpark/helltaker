#include "Player.h"
#include "../Utils/InputManager.h"
#include "../Utils/Utils.h"
#include "./Box.h"
#include "./MapCode.h"
#include "./Skull.h"

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

	this->tileSize = tileSize;
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
			return;
		}
	}

	position += (nextPosition - prevPosition) * dt / (moveSecond + MOVE_DURATION);

	sprite.setPosition(position);
}

void Player::Kick()
{
	kickVfx.Init((position + nextPosition) * 0.5f);
	animation.Play("PlayerKick");
	animation.PlayQue("PlayerStand");
}

bool Player::HanddleInput(char ** &map, std::vector<Box*>& boxes, std::vector<Skull*>& skulls)
{
	bool useTurn = false;

	if (animation.NowPlaying() != "PlayerStand" || dir != Direction::None) return useTurn;

	if (InputManager::GetKey(Keyboard::Left)) {
		sprite.setScale(-1.f, 1.f);
		nextPosition.x = position.x - tileSize;
		nextPosition.y = position.y;
		dir = Direction::Left;
	}
	if (InputManager::GetKey(Keyboard::Right)) {
		sprite.setScale(1.f, 1.f);
		nextPosition.x = position.x + tileSize;
		nextPosition.y = position.y;
		dir = Direction::Right;
	}
	if (InputManager::GetKey(Keyboard::Up)) {
		nextPosition.x = position.x;
		nextPosition.y = position.y - tileSize;
		dir = Direction::Up;
	}
	if (InputManager::GetKey(Keyboard::Down)) {
		nextPosition.x = position.x;
		nextPosition.y = position.y + tileSize;
		dir = Direction::Down;
	}

	if (dir != Direction::None) {
		switch (map[(int)nextPosition.y / tileSize][(int)nextPosition.x / tileSize]) {
		case (char)MapCode::WALL:
			dir = Direction::None;
			return useTurn;

		case (char)MapCode::BOX:
			for(auto& box : boxes) {
				if (box->IsBoxHere(nextPosition)) {
					box->Move(dir, map);
				}
			}
			Kick();
			dir = Direction::None;
			useTurn = true;
			return useTurn;

		case (char)MapCode::SKULL:
			for (auto& skull : skulls) {
				if (skull->IsSkullHere(nextPosition)) {
					skull->OnPushed(dir, map);
				}
			}
			Kick();
			dir = Direction::None;
			useTurn = true;
			return useTurn;

		default:
			break;
		}

		moveVfx.Init(position);
		map[(int)nextPosition.y / tileSize][(int)nextPosition.x / tileSize] = 'P';
		map[(int)position.y / tileSize][(int)position.x / tileSize] = 'E';
		prevPosition = position;
		animation.Play("PlayerMove");
		animation.PlayQue("PlayerStand");
		useTurn = true;
	}

	return useTurn;
}

void Player::Update(float dt)
{
	if (dir != Direction::None) Move(dt);

	moveVfx.Update(dt);
	kickVfx.Update(dt);
	animation.Update(dt);
	Utils::SetOrigin(sprite, Pivots::Center);
}

void Player::Draw(RenderWindow& window)
{
	moveVfx.Draw(window);
	window.draw(sprite);
	kickVfx.Draw(window);
}

Player::Player()
	:moveSecond(0.f), tileSize(0), dir(Direction::None), moveTime(0.f)
{
}

Vector2f Player::GetPos()
{
	return position;
}
