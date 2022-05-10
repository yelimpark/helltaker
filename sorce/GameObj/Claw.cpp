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
	animation.AddClip("DectivateClaw"); //16-20\

	isActive = true;
}

void Claw::Update(float dt)
{
	animation.Update(dt);
	Utils::SetOrigin(sprite, Pivots::Center);

	if (InputManager::GetKeyDown(Keyboard::Left))
	{
		if (!isActive)
		{
			animation.Play("ActivateClaw");
			isActive = true;
		}
		else
		{
			animation.Play("DectivateClaw");
			isActive = false;
		}
	}

	if (InputManager::GetKeyDown(Keyboard::Right))
	{
		if (!isActive)
		{
			animation.Play("ActivateClaw");
			isActive = true;
		}
		else
		{
			animation.Play("DectivateClaw");
			isActive = false;
		}
	}

	if (InputManager::GetKeyDown(Keyboard::Up))
	{
		if (!isActive)
		{
			animation.Play("ActivateClaw");
			isActive = true;
		}
		else
		{
			animation.Play("DectivateClaw");
			isActive = false;
		}
	}

	if (InputManager::GetKeyDown(Keyboard::Down))
	{
		if (!isActive)
		{
			animation.Play("ActivateClaw");
			isActive = true;
		}
		else
		{
			animation.Play("DectivateClaw");
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

bool Claw::IsInActiveClaw(char**& map, int tileSize, std::vector<Skull*>& skulls)
{
	int idxY = (int)position.y / tileSize;
	int idxX = (int)position.x / tileSize;

	if (map[idxY][idxX] == (char)MapCode::PLAYER)
	{
		return true;
	}

	for(auto& skull : skulls)
		if (map[idxY][idxX] == (char)MapCode::SKULL)
		{
			return skull->IsDead();

		}

	return false;
}
