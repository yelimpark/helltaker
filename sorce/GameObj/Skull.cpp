#include "Skull.h"
#include "../Utils/InputManager.h"
#include "../Utils/Utils.h"
#include "./MapCode.h"
#include "./Claw.h"


void Skull::Init(Vector2f pos, int tileSize, float moveSecond)
{
	position = pos;
	sprite.setPosition(position);

	animation.SetTarget(&sprite);
	animation.AddClip("SkullStand");
	animation.AddClip("SkullPushed");

	animation.Play("SkullStand");

	dir = Direction::None;
	moveDistance = tileSize;
	this->moveSecond = moveSecond;
	moveTime = moveSecond;
	isDead = false;
}

void Skull::Update(float dt)
{
	animation.Update(dt);
	Utils::SetOrigin(sprite, Pivots::Center);

	if (dir == Direction::None) return;

	moveTime -= dt;

	if (moveTime <= 0)
	{
		moveTime = moveSecond;
		position = nextPosition;
		dir = Direction::None;
	}

	switch (dir)
	{
	case Direction::Left:
		position.x -= moveDistance * dt / moveSecond;
		break;

	case Direction::Right:
		position.x += moveDistance * dt / moveSecond;
		break;

	case Direction::Up:
		position.y -= moveDistance * dt / moveSecond;
		break;

	case Direction::Down:
		position.y += moveDistance * dt / moveSecond;
		break;

	default:
		break;
	}

	sprite.setPosition(position);
}

void Skull::OnPushed(Direction dir, char**& map)
{
	this->dir = dir;
	animation.Play("SkullPushed");
	animation.PlayQue("SkullStand");

	nextPosition = position;
	switch (dir)
	{
	case Direction::Left:
		nextPosition.x = position.x - moveDistance;
		break;

	case Direction::Right:
		nextPosition.x = position.x + moveDistance;
		break;

	case Direction::Up:
		nextPosition.y = position.y - moveDistance;
		break;

	case Direction::Down:
		nextPosition.y = position.y + moveDistance;
		break;

	default:
		break;
	}

	Vector2i curIdx = Utils::PosToIdx(position);
	Vector2i nextIdx = Utils::PosToIdx(nextPosition);

	switch (map[nextIdx.y][nextIdx.x])
	{
	case (char)MapCode::WALL:
	case (char)MapCode::BOX:
	case (char)MapCode::LOCKEDBOX:
	case (char)MapCode::DEMON:
	case (char)MapCode::SKULL:
		isDead = true;
		map[curIdx.y][curIdx.x] = 'E';
		return;
	default:
		break;
	}

	map[curIdx.y][curIdx.x] = 'E';
	map[nextIdx.y][nextIdx.x] = 'S';
}

void Skull::Draw(RenderWindow& window)
{
	window.draw(sprite);
}

const Vector2f& Skull::GetPos()
{
	return position;
}

const bool Skull::IsSkullHere(Vector2f pos)
{
	return (int)(pos.x / moveDistance) == (int)(position.x / moveDistance) &&
		(int)(pos.y / moveDistance) == (int)(position.y / moveDistance);
}

const bool Skull::IsDead()
{
	return isDead;
}
