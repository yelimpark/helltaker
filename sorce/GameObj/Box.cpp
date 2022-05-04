#include "Box.h"
#include "../Resource/TextureHolder.h"
#include <sstream>
#include <vector>


Box::Box()
	: isMoving(false), speedX(0), speedY(0)
{
}

void Box::Init()
{
	
}

void Box::Moved(Direction dir)
{
	
}

void Box::Update(float dt)
{
	if (isMoving)
	{
		Vector2f boxPos = box.getPosition();
		switch (dir)
		{
		case Direction::Left:
			boxPos.x = speedX * dt * -1;
			box.setPosition(boxPos);
			break;

		case Direction::Right:
			boxPos.x = speedX * dt;
			box.setPosition(boxPos);
			break;

		case Direction::Up:
			boxPos.y = speedY * dt;
			box.setPosition(boxPos);
			break;

		case Direction::Down:
			boxPos.y = speedY * dt;
			box.setPosition(boxPos);
			break;
		}
	}
}

void Box::Draw(RenderWindow& window)
{
	window.draw(box);
}
