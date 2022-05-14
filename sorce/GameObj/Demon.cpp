#include "Demon.h"
#include "./MapCode.h"
#include "../Utils/Utils.h"
#include "../Resource/TextureHolder.h"

void Demon::Init(Vector2f pos, std::string demonName)
{
	position = pos;
	sprite.setPosition(position);

	animation.SetTarget(&sprite);
	animation.AddClip(demonName);
	animation.Play(demonName);

	heartYPos = 60.f;
	heart.setTexture(TextureHolder::GetTexture("Sprite/lovesign.png"));
}

void Demon::Update(float dt)
{
	animation.Update(dt);
	Utils::SetOrigin(sprite, Pivots::Center);

	heart.setPosition(position.x - 55.f, position.y - heartYPos);

	if (heartYPos > 60)
	{
		dir = -1.f;
	}

	else if (heartYPos < 50)
	{
		dir = 1.f;
	}

	if (isheartmoving || heartYPos <= 55)
	{
		heartYPos += dir * dt * 50;
	}

	isheartmoving = true;
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
