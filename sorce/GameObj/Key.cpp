#include "Key.h"
#include "../Utils/Utils.h"

Key::Key()
	:isActive(false), isEarned(false), position(-500, -500)
{
	sprite.setPosition(position);
}

void Key::Init(Vector2f pos)
{
	position = pos;
	sprite.setPosition(position);
	vfxSprite.setPosition(position);

	animation.SetTarget(&sprite);
	animation.AddClip("Key");
	animation.Play("Key");

	vfxAnimation.SetTarget(&vfxSprite);
	vfxAnimation.AddClip("huge_vfx");
	vfxAnimation.Play("huge_vfx");

	isEarned = false;
	isActive = true;
}

void Key::Update(float dt, Vector2f playerpos, int tileSize)
{
	if (!isActive) return;

	bool sameY = (int)position.y / tileSize == (int)playerpos.y / tileSize;
	bool sameX = (int)position.x / tileSize == (int)playerpos.x / tileSize;

	if (sameY && sameX)	isEarned = true;

	animation.Update(dt);
	Utils::SetOrigin(sprite, Pivots::Center);

	if (isEarned) {
		if (vfxAnimation.IsAnimationEnd()) {
			isActive = false;
		}
		else {
			vfxAnimation.Update(dt);
			Utils::SetOrigin(vfxSprite, Pivots::Center);
		}
	}
}

void Key::Draw(RenderWindow& window)
{
	if (!isActive) return;
	window.draw(sprite);
	if (isEarned) window.draw(vfxSprite);
}

bool Key::IsCapturedPlayer()
{
	return isEarned;
}
