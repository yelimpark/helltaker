#include "Demon.h"
#include "./MapCode.h"
#include "../Utils/Utils.h"
#include "../Resource/TextureHolder.h"

void Demon::Init(Vector2f pos)
{
	position = pos;
	sprite.setPosition(position);

	animation.SetTarget(&sprite);
	animation.AddClip("Pandemonica");
	animation.Play("Pandemonica");

	heartYPos = 55.f;
	heart.setPosition(position.x - 55.f, position.y - heartYPos);
	heart.setTexture(TextureHolder::GetTexture("Sprite/lovesign.png"));
}

void Demon::Update(float dt)
{
	animation.Update(dt);
	Utils::SetOrigin(sprite, Pivots::Center);

	heart.setPosition(position.x - 55.f, position.y - heartYPos);

	static float dir = 1.f;
	if (heartYPos > 60)
	{
		dir = -1.f;
	}

	if (heartYPos <= 50)
	{
		dir = 1.f;
	}
	heartYPos += dir * dt * 50;
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
	window.draw(heart);
}
