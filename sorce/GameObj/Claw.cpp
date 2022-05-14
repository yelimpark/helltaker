#include "Claw.h"
#include "./MapCode.h"
#include "../Resource/TextureHolder.h"
#include "../Utils/Utils.h"
#include "../Utils/InputManager.h"

#include <iostream>


void Claw::Init(Vector2f pos, int tileSize)
{
	position = pos;
	sprite.setTexture(TextureHolder::GetTexture("Sprite/assets100V20116.png"));
	sprite.setPosition(position);

	animation.SetTarget(&sprite);
	animation.AddClip("ActivateClaw"); //20-23
	animation.AddClip("DeactivateClaw"); //16-20\

	isActive = true;
}

void Claw::Update(float dt)
{
	animation.Update(dt);
	Utils::SetOrigin(sprite, Pivots::Center);

	if (InputManager::GetKeyDown(Keyboard::Left) ||
		InputManager::GetKeyDown(Keyboard::Right) ||
		InputManager::GetKeyDown(Keyboard::Up) ||
		InputManager::GetKeyDown(Keyboard::Down))
	{
		if (!isActive)
		{
			animation.Play("ActivateClaw");
			isActive = true;
		}
		else
		{
			animation.Play("DeactivateClaw");
			isActive = false;
		}
	}
}

void Claw::ActivateClaw(bool isActive)
{
}

void Claw::DeactivateClaw()
{
}

void Claw::Draw(RenderWindow& window)
{
	window.draw(sprite);
}

bool Claw::IsActive()
{
	return isActive;
}

bool Claw::IsSkullIn(char**& map, int tileSize, Skull* skull)
{
	int idxY = (int)position.y / tileSize;
	int idxX = (int)position.x / tileSize;

	if (map[idxY][idxX] == (char)MapCode::SKULL)
	{
		return true;
	}
	return false;
}

bool Claw::IsPlayerIn(char**& map, int tileSize)
{
	int idxY = (int)position.y / tileSize;
	int idxX = (int)position.x / tileSize;

	if (map[idxY][idxX] == (char)MapCode::PLAYER)
	{
		return true;
	}

	return false;
}
