#include "Box.h"
#include "../Resource/TextureHolder.h"

std::vector<boxInfo> Box::boxes;

Box::Box()
	: isMoving(false), speedX(0), speedY(0)
{
}

void Box::Init()
{
	vector<boxInfo> boxes(4);
	{
		auto& info = boxes[(int)box::box001];
		info.type = box::box001;
		info.textureFilename = "Sprite/boxExport0001.png";
	}
	{
		auto& info = boxes[(int)box::box003];
		info.type = box::box003;
		info.textureFilename = "Sprite/boxExport0002.png";
	}
	{
		auto& info = boxes[(int)box::box004];
		info.type = box::box004;
		info.textureFilename = "Sprite/boxExport0004.png";
	}
	{
		auto& info = boxes[(int)box::box008];
		info.type = box::box008;
		info.textureFilename = "Sprite/boxExport0008.png";
	}
}

void Box::Moved(Direction dir)
{
	
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
