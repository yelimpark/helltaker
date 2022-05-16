#include "LockedBox.h"
#include "../Resource/TextureHolder.h"
#include "../Utils/Utils.h"

LockedBox::LockedBox()
	:isActive(false), isEarned(false), isopen(false), position(-500, -500), shakeDir(Direction::None), shakeTime(2.f)
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

	isActive = true;
	isEarned = false;
	isopen = false;
	shakeDir = Direction::None;
	shakeTime = 2.f;
}

void LockedBox::Update(float dt, bool isopen, Vector2f playerpos, int tileSize)
{
	if (!isActive) return;

	this->isopen = isopen;

	if (Utils::PosToIdx(position) == Utils::PosToIdx(playerpos)) isEarned = true;

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

	switch (shakeDir)
	{
	case Direction::Left:
	case Direction::Right:
		sprite.setPosition(position.x + dt * 800, position.y);
		shakeTime -= dt * 10;
		break;
	case Direction::Down:
	case Direction::Up:
		sprite.setPosition(position.x, position.y + dt * 800);
		shakeTime -= dt * 10;
		break;
	default:
		break;
	}

	if (shakeTime < 0.0f)
	{
		shakeDir = Direction::None;
		shakeTime = 2.f;
		sprite.setPosition(position);
	}
}

void LockedBox::Shake(Direction dir)
{
	this->shakeDir = dir;
}

void LockedBox::Draw(RenderWindow& window)
{
	if (!isActive) return;
	if (isEarned) window.draw(vfxSprite);
	else window.draw(sprite);
}

bool LockedBox::IsOpen()
{
	return isopen;
}
