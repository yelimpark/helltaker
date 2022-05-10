#include "LockedBox.h"
#include "./MapCode.h"
#include "../Resource/TextureHolder.h"
#include "../Utils/Utils.h"

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
		return true;
	}
	return false;
}


