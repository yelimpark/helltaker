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

	if (Utils::PosToIdx(position) == Utils::PosToIdx(playerpos)) isEarned = true;

	animation.Update(dt);
	Utils::SetOrigin(sprite, Pivots::Center);

	if (isEarned) {
		soundEffects.SoundEffectPlay("Sound/key_pick_up_01.wav");
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
	if (isEarned) window.draw(vfxSprite);
	else window.draw(sprite);
}

bool Key::IsCapturedPlayer()
{
	return isEarned;
}
