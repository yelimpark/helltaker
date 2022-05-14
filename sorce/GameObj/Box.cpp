#include "Box.h"
#include "../Resource/TextureHolder.h"
#include "../Utils/InputManager.h"
#include "../Utils/Utils.h"
#include "./MapCode.h"
#include <iostream>

Box::Box()
	: moveSecond(0), dir(Direction::None), moveDistance(0.f), moveTime(moveSecond), playTime(2.f)
{
}

void Box::Init(BoxData info, int tileSize, float moveSecond)
{
	position = info.position;
	sprite.setTexture(TextureHolder::GetTexture(info.textureFilename));
	Utils::SetOrigin(sprite, Pivots::Center);
	sprite.setPosition(position);

	dir = Direction::None;
	moveDistance = tileSize;
	this->moveSecond = moveSecond;
	moveTime = moveSecond;

	playTime = 2.f;
}

bool Box::Move(Direction dir, char**& map)
{
	this->dir = dir;

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

	switch (map[(int)nextPosition.y / moveDistance][(int)nextPosition.x / moveDistance])
	{
	case (char)MapCode::WALL:
	case (char)MapCode::BOX:
	case (char)MapCode::LOCKEDBOX:
	case (char)MapCode::DEMON:
	case (char)MapCode::SKULL:
		this->dir = Direction::None;
		shakeDir = dir;
		return false;

	default:
		break;
	}

	map[(int)position.y / moveDistance][(int)position.x / moveDistance] = 'E';
	map[(int)nextPosition.y / moveDistance][(int)nextPosition.x / moveDistance] = 'B';
	return true;
}

void Box::Update(float dt)
{
	switch (shakeDir)
	{
	case Direction::Left:
	case Direction::Right:
		sprite.setPosition(position.x + dt * 800, position.y);
		break;
	case Direction::Down:
	case Direction::Up:
		sprite.setPosition(position.x, position.y + dt * 800);
		break;
	default:
		break;
	}

	playTime -= dt * 10;

	if (playTime < 0.0f)
	{
		shakeDir = Direction::None;
		playTime = 2.f;
		sprite.setPosition(position);
	}

	if (dir == Direction::None)		return;

	moveTime -= dt;

	if (moveTime <= 0)
	{
		moveTime = moveSecond;
		position = nextPosition;
		sprite.setPosition(position);
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

void Box::Draw(RenderWindow& window)
{
	window.draw(sprite);
}

const Vector2f& Box::GetPos()
{
	return position;
}

const bool Box::IsBoxHere(Vector2f pos)
{
	return (int)(pos.x / moveDistance) == (int)(position.x / moveDistance) &&
		(int)(pos.y / moveDistance) == (int)(position.y / moveDistance);
}
