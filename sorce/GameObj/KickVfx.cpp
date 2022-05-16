#include "KickVfx.h"
#include "../Utils/Utils.h"

KickVfx::KickVfx()
{
}

void KickVfx::Init(Vector2f pos, bool isItMove)
{
	sprite.setPosition(pos);
	animation.SetTarget(&sprite);
	if (isItMove) {
		animation.AddClip("kick_vfx");
		animation.Play("kick_vfx");
	}
	else {
		animation.AddClip("small_vfx");
		animation.Play("small_vfx");
	}
}

void KickVfx::Update(float dt)
{
	animation.Update(dt);
	Utils::SetOrigin(sprite, Pivots::Center);
}

void KickVfx::Draw(RenderWindow& window)
{
	if (animation.IsAnimationEnd()) return;
	window.draw(sprite);
}
