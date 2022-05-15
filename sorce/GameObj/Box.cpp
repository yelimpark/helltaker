#include "Box.h"
#include "../Resource/TextureHolder.h"
#include "../Utils/InputManager.h"
#include "../Utils/Utils.h"
#include "./MapCode.h"
#include <iostream>

Box::Box()
	: moveSecond(0), dir(Direction::None), moveDistance(0.f), moveTime(moveSecond), shakeTime(2.f), shakeDir(Direction::None)
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

	shakeTime = 2.f;
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

	Vector2i curIdx = Utils::PosToIdx(position);
	Vector2i nextIdx = Utils::PosToIdx(nextPosition);

	switch (map[nextIdx.y][nextIdx.x])
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

	map[curIdx.y][curIdx.x] = 'E';
	map[nextIdx.y][nextIdx.x] = 'B';
	return true;
}

void Box::Update(float dt)
{

	if (shakeDir != Direction::None) shakeTime -= dt * 10;

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

	if (shakeTime < 0.0f)
	{
		shakeDir = Direction::None;
		shakeTime = 2.f;
		sprite.setPosition(position);
	}

	if (dir == Direction::None)	return;

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
	return Utils::PosToIdx(position) == Utils::PosToIdx(pos);
}
