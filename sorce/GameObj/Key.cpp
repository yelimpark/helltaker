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

	getVfx.Init(pos);
	isEarned = false;
}

void Key::Update(float dt)
{
	animation.Update(dt);
	if (isEarned) {
		getVfx.Update(dt);
	}

	Utils::SetOrigin(sprite, Pivots::Center);
}

void Key::Draw(RenderWindow& window)
{
	window.draw(sprite);
	if (isEarned) {
		getVfx.Draw(window);
	}
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
		isEarned = true;
		return true;
	}
	isEarned = false;
	return false;
}

Vector2f Key::GetKeyPos()
{
	return position;
}
