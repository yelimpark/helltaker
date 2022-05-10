#include "Key.h"
#include "./MapCode.h"
#include "../Utils/Utils.h"


void Key::Init(Vector2f pos, int tileSize)
{
	position = pos;
	sprite.setPosition(position);

	animation.SetTarget(&sprite);
	animation.AddClip("Key");
	animation.Play("Key");
}

void Key::Update(float dt)
{
	animation.Update(dt);
	Utils::SetOrigin(sprite, Pivots::Center);
}

void Key::Draw(RenderWindow& window)
{
	window.draw(sprite);
}

void Key::Clear()
{
	sprite.setPosition(2000, 1500);
}

bool Key::IsCapturedPlayer(char**& map, int tileSize)
{
	int idxY = (int)position.y / tileSize;
	int idxX = (int)position.x / tileSize;

	if (map[idxY][idxX] == (char)MapCode::PLAYER)
	{
		return true;
	}
	return false;
}
