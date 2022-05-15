#include "Player.h"
#include "../Utils/InputManager.h"
#include "../Utils/Utils.h"
#include "./Box.h"
#include "./MapCode.h"
#include "./Skull.h"
#include "./Key.h"
#include "./LockedBox.h"
#include "../Utils/SceneManager.h"

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

void Player::Kick(bool isItMove)
{
	kickVfx.Init((position + nextPosition) * 0.5f, isItMove);
	animation.Play("PlayerKick");
	animation.PlayQue("PlayerStand");
}

bool Player::HanddleInput(char ** &map, std::vector<Box*>& boxes, std::vector<Skull*>& skulls, LockedBox &lockedbox)
{
	bool useTurn = false;

	if (animation.NowPlaying() != "PlayerStand" || dir != Direction::None) return useTurn;

	nextPosition = position;
	if (InputManager::GetKey(Keyboard::Left)) {
		sprite.setScale(-1.f, 1.f);
		nextPosition.x = position.x - tileSize;
		dir = Direction::Left;
	}
	if (InputManager::GetKey(Keyboard::Right)) {
		sprite.setScale(1.f, 1.f);
		nextPosition.x = position.x + tileSize;
		dir = Direction::Right;
	}
	if (InputManager::GetKey(Keyboard::Up)) {
		nextPosition.y = position.y - tileSize;
		dir = Direction::Up;
	}
	if (InputManager::GetKey(Keyboard::Down)) {
		nextPosition.y = position.y + tileSize;
		dir = Direction::Down;
	}

	Vector2i nextIdx = Utils::PosToIdx(nextPosition);

	if (dir != Direction::None) {
		switch (map[nextIdx.y][nextIdx.x]) {
		case (char)MapCode::WALL:
			dir = Direction::None;
			return useTurn;	

		case (char)MapCode::BOX:
			for(auto& box : boxes) {
				if (box->IsBoxHere(nextPosition)) {
					Kick(box->Move(dir, map));
					soundEffects.SoundEffectPlay("Sound/stone_move_01.wav");
				}
			}
			Kick(true);
			dir = Direction::None;
			useTurn = true;
			return useTurn;

		case (char)MapCode::SKULL:
			for (auto& skull : skulls) {
				if (skull->IsSkullHere(nextPosition)) {
					skull->OnPushed(dir, map);
					soundEffects.SoundEffectPlay("Sound/enemy_kick_01.wav");
				}
			}
			Kick(true);
			dir = Direction::None;
			useTurn = true;
			return useTurn;

		case (char)MapCode::LOCKEDBOX:
			if (!lockedbox.IsOpen()) {
				Kick(false);
				lockedbox.Shake(dir);
				dir = Direction::None;
				useTurn = true;
				return useTurn;
			}

		default:
			break;
		}

		soundEffects.SoundEffectPlay("Sound/character_move_01.wav");
		moveVfx.Init(position);

		Vector2i curIdx = Utils::PosToIdx(position);
		map[curIdx.y][curIdx.x] = 'E';

		map[nextIdx.y][nextIdx.x] = 'P';

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
