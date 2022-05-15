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

	heartDir = 1.f;
	isheartmoving = false;
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
		heartDir = -1.f;
	}
	else if (heartYPos < 50)
	{
		heartDir = 1.f;
	}

	if (isheartmoving || heartYPos <= 55)
	{
		heartYPos += heartDir * dt * 50;
	}

	isheartmoving = true;
}

bool Demon::IsClear(char**& map, int tileSize)
{
	Vector2i idx = Utils::PosToIdx(position);

	if (map[idx.y + 1][idx.x] == (char)MapCode::PLAYER ||
		map[idx.y - 1][idx.x] == (char)MapCode::PLAYER ||
		map[idx.y][idx.x + 1] == (char)MapCode::PLAYER ||
		map[idx.y][idx.x - 1] == (char)MapCode::PLAYER )
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
