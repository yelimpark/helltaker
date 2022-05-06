#include "Box.h"
#include "../Resource/TextureHolder.h"
#include "../Utils/InputManager.h"
#include <sstream>
#include <vector>


Box::Box()
	: isMoving(false), MOVE_DISTANCE(0)
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

void Box::Moved(float dt)
{
	isMoving = true;
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
