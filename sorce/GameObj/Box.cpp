#include "Box.h"
#include "../Resource/TextureHolder.h"
#include "../Utils/InputManager.h"
#include <sstream>
#include <vector>


Box::Box()
	: isMoving(false), MOVE_DISTANCE(0), dir(Direction::None), moveTime(MOVE_SECOND)
{
}

void Box::Init(BoxData info, int tileSize)
{
	MOVE_DISTANCE = tileSize;
	position = info.position;
	sprite.setTexture(TextureHolder::GetTexture(info.textureFilename));
	sprite.setPosition(position);

	moveTime = MOVE_SECOND;
	isMoving = false;
}

void Box::Moved(Direction dir)
{
	isMoving = true;
	this->dir = dir;
}

void Box::Update(float dt)
{
	if (!isMoving) return;

	moveTime -= dt;

	if (moveTime <= 0)
	{
		moveTime = MOVE_SECOND;
		isMoving = false;
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

	case Direction::Up:
		position.y -= MOVE_DISTANCE * dt / MOVE_SECOND;
		break;

	case Direction::Down:
		position.y += MOVE_DISTANCE * dt / MOVE_SECOND;
		break;

	case Direction::None:
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
	return (int)(pos.x / MOVE_DISTANCE) == (int)(position.x / MOVE_DISTANCE) &&
		(int)(pos.y / MOVE_DISTANCE) == (int)(position.y / MOVE_DISTANCE);
}
