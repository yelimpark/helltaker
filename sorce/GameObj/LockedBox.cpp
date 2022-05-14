#include "LockedBox.h"
#include "../Resource/TextureHolder.h"
#include "../Utils/Utils.h"

LockedBox::LockedBox()
	:isActive(false), isEarned(false), isopen(false), position(-500, -500), dir(Direction::None), playtime(2.f)
{
	sprite.setPosition(position);
}

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

	isActive = true;
	isEarned = false;
	isopen = false;
	dir = Direction::None;
	playtime = 2.f;
}

void LockedBox::Update(float dt, bool isopen, Vector2f playerpos, int tileSize)
{
	if (!isActive) return;

	this->isopen = isopen;

	bool sameY = (int)position.y / tileSize == (int)playerpos.y / tileSize;
	bool sameX = (int)position.x / tileSize == (int)playerpos.x / tileSize;

	if (sameY && sameX && isopen)	isEarned = true;

	if (isEarned)
	{
		if (vfxAnimation.IsAnimationEnd())
		{
			isActive = false;
		}
		else
		{
			vfxAnimation.Update(dt);
			Utils::SetOrigin(vfxSprite, Pivots::Center);
		}
	}

	switch (dir)
	{
	case Direction::Left:
	case Direction::Right:
		sprite.setPosition(position.x + dt * 800, position.y);
		playtime -= dt * 10;
		break;
	case Direction::Down:
	case Direction::Up:
		sprite.setPosition(position.x, position.y + dt * 800);
		playtime -= dt * 10;
		break;
	default:
		break;
	}

	if (playtime < 0.0f)
	{
		dir = Direction::None;
		playtime = 2.f;
		sprite.setPosition(position);
	}
}

void LockedBox::Shake(Direction dir)
{
	this->dir = dir;
}

void LockedBox::Draw(RenderWindow& window)
{
	if (!isActive) return;
	window.draw(sprite);
	if (isEarned)
	{
		window.draw(vfxSprite);
	}
}

bool LockedBox::IsOpen()
{
	return isopen;
}
