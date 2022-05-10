#include "GetVfx.h"
#include "../Utils/Utils.h"

void GetVfx::Init(Vector2f keyPos)
{
	sprite.setPosition(keyPos);
	animation.SetTarget(&sprite);
	animation.AddClip("huge_vfx");
	animation.Play("huge_vfx");
}

void GetVfx::Update(float dt)
{
	animation.Update(dt);
	Utils::SetOrigin(sprite, Pivots::Center);
}

void GetVfx::Draw(RenderWindow& window)
{
	if (animation.IsAnimationEnd()) return;
	window.draw(sprite);
}
