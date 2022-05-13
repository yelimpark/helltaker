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
	isSideShake = false;
	isUpShake = false;
	playtime = 2.f;
}

void LockedBox::Update(float dt)
{
	if (isSideShake)
	{
		sprite.setPosition(position.x + dt * 800, position.y);
	}
	if (isUpShake)
	{
		sprite.setPosition(position.x, position.y + dt * 800);
	}

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

	playtime -= dt * 10;

	if (playtime < 0.0f)
	{
		isSideShake = false;
		isUpShake = false;
		playtime = 2.f;
		sprite.setPosition(position);
	}
}

void LockedBox::Shake(Direction dir)
{
	if (dir == Direction::Left || dir == Direction::Right)
		isSideShake = true;
	if (dir == Direction::Up || dir == Direction::Down)
		isUpShake = true;
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

