#include "Skull.h"
#include "../Utils/InputManager.h"
#include "../Utils/Utils.h"
#include "./MapCode.h"


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
		dir = Direction::None;
		return;
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

	char* nextPos = &map[(int)position.y / moveDistance][(int)position.x / moveDistance];

	switch (dir)
	{
	case Direction::Left:
		nextPos = &map[(int)position.y / moveDistance][(int)position.x / moveDistance - 1];
		break;

	case Direction::Right:
		nextPos = &map[(int)position.y / moveDistance][(int)position.x / moveDistance + 1];
		break;

	case Direction::Up:
		nextPos = &map[(int)position.y / moveDistance - 1][(int)position.x / moveDistance];
		break;

	case Direction::Down:
		nextPos = &map[(int)position.y / moveDistance + 1][(int)position.x / moveDistance];
		break;

	default:
		break;
	}

	switch (*nextPos)
	{
	case (char)MapCode::WALL:
	case (char)MapCode::BOX:
	case (char)MapCode::SKULL:
		isDead = true;
		map[(int)position.y / moveDistance][(int)position.x / moveDistance] = 'E';
		return;
	case (char)MapCode::CLAW:

	default:
		break;
	}

	map[(int)position.y / moveDistance][(int)position.x / moveDistance] = 'E';
	*nextPos = 'S';
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
