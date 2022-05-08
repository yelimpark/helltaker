#include "KickVfx.h"
#include "../Utils/Utils.h"

KickVfx::KickVfx()
{
}

void KickVfx::Init(Vector2f pos)
{
	sprite.setPosition(pos);
	animation.SetTarget(&sprite);
	animation.AddClip("kick_vfx");
	animation.Play("kick_vfx");
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
