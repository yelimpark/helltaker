#include "Box.h"
#include "../Resource/TextureHolder.h"
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

void Box::Moved(Direction dir)
{
	isMoving = true;
}

void Box::Update(float dt)
{
	if (isMoving)
	{
		Vector2f boxPos = sprite.getPosition();
		switch (dir)
		{
		case Direction::Left:
			boxPos.x = speedX * dt * -1;
			sprite.setPosition(boxPos);
			break;

		case Direction::Right:
			boxPos.x = speedX * dt;
			sprite.setPosition(boxPos);
			break;

		case Direction::Up:
			boxPos.y = speedY * dt;
			sprite.setPosition(boxPos);
			break;

		case Direction::Down:
			boxPos.y = speedY * dt;
			sprite.setPosition(boxPos);
			break;
		}
	}
}

void Box::Draw(RenderWindow& window)
{
	window.draw(sprite);
}
