#include "Box.h"
#include "../Resource/TextureHolder.h"
#include "../Utils/InputManager.h"
#include <sstream>
#include <vector>


Box::Box()
	: isMoving(false)
{
}

void Box::Init(boxInfo info)
{
	position = info.position;
	sprite.setTexture(TextureHolder::GetTexture(info.textureFilename));
	sprite.setPosition(position);

	moveTime = MOVE_SECOND;
	isMoving = false;
}

void Box::Moved(float dt)
{
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

void Box::Update(float dt)
{
	if (isMoving)
	{
		Moved(dt);
	}

	if (InputManager::GetKeyDown(Keyboard::Left))
	{
		isMoving = true;
		dir = Direction::Left;
	}

	else if (InputManager::GetKeyDown(Keyboard::Right))
	{
		isMoving = true;
		dir = Direction::Right;
	}

	else if (InputManager::GetKeyDown(Keyboard::Up))
	{
		isMoving = true;
		dir = Direction::Up;
	}

	else if (InputManager::GetKeyDown(Keyboard::Down))
	{
		isMoving = true;
		dir = Direction::Down;
	}
}

void Box::Draw(RenderWindow& window)
{
	window.draw(sprite);
}
