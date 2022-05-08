#include "Box.h"
#include "../Resource/TextureHolder.h"
#include "../Utils/InputManager.h"
#include "./MapCode.h"

Box::Box()
	: moveSecond(0), dir(Direction::None), moveDistance(0.f), moveTime(moveSecond)
{
}

void Box::Init(BoxData info, int tileSize, float moveSecond)
{
	position = info.position;
	sprite.setTexture(TextureHolder::GetTexture(info.textureFilename));
	sprite.setPosition(position);

	dir = Direction::None;
	moveDistance = tileSize;
	this->moveSecond = moveSecond;
	moveTime = moveSecond;
}

void Box::Move(Direction dir, char**& map)
{
	this->dir = dir;

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
		this->dir = Direction::None;
		return;

	default:
		break;
	}

	map[(int)position.y / moveDistance][(int)position.x / moveDistance] = 'E';
	*nextPos = 'B';

}

void Box::Update(float dt)
{
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
