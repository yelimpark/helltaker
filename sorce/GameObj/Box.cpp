#include "Box.h"
#include "../Resource/TextureHolder.h"
#include "../Utils/InputManager.h"
#include <sstream>
#include <vector>


Box::Box()
	: isMoving(false), speedX(800.f), speedY(800.f)
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
	

	switch (dir)
	{
	case Direction::Left:
		position.x -= speedX * dt;
		break;

	case Direction::Right:
		position.x += speedX * dt;

		break;

	case Direction::Up:
		position.y -= speedY * dt;
		break;

	case Direction::Down:
		position.y += speedY * dt;
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
	Moved(dt);
	if (InputManager::GetKey(Keyboard::Left))
	{
		isMoving = true;
		dir = Direction::Left;
	}

	else if (InputManager::GetKey(Keyboard::Right))
	{
		isMoving = true;
		dir = Direction::Right;
	}

	else if (InputManager::GetKey(Keyboard::Up))
	{
		isMoving = true;
		dir = Direction::Up;
	}

	else if (InputManager::GetKey(Keyboard::Down))
	{
		isMoving = true;
		dir = Direction::Down;
	}
	else
	{
		isMoving = false;
		dir = Direction::None;
	}
}

void Box::Draw(RenderWindow& window)
{
	window.draw(sprite);
}
