#include "LockedBox.h"
#include "./MapCode.h"
#include "../Resource/TextureHolder.h"
#include "../Utils/Utils.h"
#include "../Utils/InputManager.h"

void LockedBox::Init(Vector2f pos)
{
	position = pos;
	sprite.setPosition(position);
	sprite.setTexture(TextureHolder::GetTexture("Sprite/backup_lockbox.png"));
	Utils::SetOrigin(sprite, Pivots::Center);

	vfxSprite.setPosition(position);
	vfxAnimation.SetTarget(&vfxSprite);
	vfxAnimation.AddClip("huge_vfx");
	vfxAnimation.Play("huge_vfx");

	velocity = Vector2f(0.f, 0.f);

	isEarned = false;
}

void LockedBox::Update(float dt)
{
	if (isEarned)
	{
		if (vfxAnimation.IsAnimationEnd())
		{
			isEarned = false;
		}
		else
		{
			vfxAnimation.Update(dt);
			Utils::SetOrigin(vfxSprite, Pivots::Center);
		}
	}
}

void LockedBox::Shake(float dt)
{
	if (InputManager::GetKeyDown(Keyboard::Left) || InputManager::GetKeyDown(Keyboard::Right))
	{
		std::cout << "되는거냐" << std::endl;
		sprite.setPosition(Vector2f(position.x + dt * 1200, position.y));
	}
	if (InputManager::GetKeyDown(Keyboard::Up) || InputManager::GetKeyDown(Keyboard::Down))
	{
		std::cout << "이놈아!!" << std::endl;
		sprite.setPosition(Vector2f(position.x, position.y + dt * 1200));
	}
}

void LockedBox::Draw(RenderWindow& window)
{
	window.draw(sprite);
	if (isEarned)
	{
		window.draw(vfxSprite);
		
	}
}

void LockedBox::Clear()
{
	sprite.setPosition(2200, 1800);
}

bool LockedBox::IsCapturedPlayer(char**& map, int tileSize)
{
	int idxY = (int)position.y / tileSize;
	int idxX = (int)position.x / tileSize;

	if (map[idxY][idxX] == (char)MapCode::PLAYER)
	{
		isEarned = true;
		return isEarned;
	}
	return isEarned;
}


