#include "Demon.h"
#include "./MapCode.h"
#include "../Utils/Utils.h"

void Demon::Init(Vector2f pos)
{
	position = pos;
	sprite.setPosition(position);

	animation.SetTarget(&sprite);
	animation.AddClip("Pandemonica");
	animation.Play("Pandemonica");
}

void Demon::Update(float dt)
{
	animation.Update(dt);
	Utils::SetOrigin(sprite, Pivots::Center);
}

bool Demon::IsClear(char**& map, int tileSize)
{
	int idxY = (int)position.y / tileSize;
	int idxX = (int)position.x / tileSize;

	if (map[idxY + 1][idxX] == (char)MapCode::PLAYER ||
		map[idxY - 1][idxX] == (char)MapCode::PLAYER ||
		map[idxY][idxX + 1] == (char)MapCode::PLAYER ||
		map[idxY][idxX - 1] == (char)MapCode::PLAYER ) 
	{
		return true;
	}

	return false;
}

void Demon::Draw(RenderWindow& window)
{
	window.draw(sprite);
}
