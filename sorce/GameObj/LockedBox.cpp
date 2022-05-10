#include "LockedBox.h"
#include "./MapCode.h"
#include "../Resource/TextureHolder.h"
#include "../Utils/Utils.h"
#include <iostream>

void LockedBox::Init(Vector2f pos)
{
	position = pos;
	sprite.setPosition(position);
	sprite.setTexture(TextureHolder::GetTexture("Sprite/backup_lockbox.png"));
	Utils::SetOrigin(sprite, Pivots::Center);

	isEarned = false;
}

void LockedBox::Update()
{

}

void LockedBox::Draw(RenderWindow& window)
{
	window.draw(sprite);
}

void LockedBox::Clear()
{
	sprite.setPosition(2000, 1500);
}

bool LockedBox::IsCapturedPlayer(char**& map, int tileSize)
{
	int idxY = (int)position.y / tileSize;
	int idxX = (int)position.x / tileSize;

	if (map[idxY][idxX] == (char)MapCode::PLAYER)
	{
		std::cout << "플레이어들어옴" << std::endl;
		isEarned = true;
		return true;
	}
	return false;
}
