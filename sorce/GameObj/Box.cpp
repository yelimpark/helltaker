#include "Box.h"
#include "../Resource/TextureHolder.h"
#include "../Utils/InputManager.h"
#include <sstream>
#include <vector>


Box::Box()
	: isMoving(false), speedX(0), speedY(0)
{
}

void Box::Init(boxInfo info)
{
	position = info.position;
	sprite.setTexture(TextureHolder::GetTexture(info.textureFilename));
	sprite.setPosition(position);

	isMoving = false;
}

void Box::Moved(float dt)
{
	Vector2f boxPos = sprite.getPosition();
	switch (dir)
	{
	case Direction::Left:
		boxPos.x -= speedX * dt;
		break;

	case Direction::Right:
		boxPos.x += speedX * dt;

		break;

	case Direction::Up:
		boxPos.y -= speedY * dt;
		break;

	case Direction::Down:
		boxPos.y += speedY * dt;
		break;

	case Direction::None:
		break;

	default:
		break;
	}

	sprite.setPosition(position);
	isMoving = true;
}

void Box::Update(float dt)
{
	Moved(dt);
	if (InputManager::GetKey(Keyboard::Left))
	{
		isMoving = true;
		dir = Direction::Left;
		sprite.setScale(-1.f, 1.f);
	}

	if (InputManager::GetKey(Keyboard::Right))
	{
		isMoving = true;
		dir = Direction::Right;
		Vector2f movePos = Vector2f(position.x , position.y);
		sprite.setPosition(movePos);
		position = movePos;
		sprite.getPosition();

	}

	if (InputManager::GetKey(Keyboard::Up))
	{
		isMoving = true;
		dir = Direction::Up;
	}
}

void Box::Draw(RenderWindow& window)
{
	window.draw(sprite);
}
