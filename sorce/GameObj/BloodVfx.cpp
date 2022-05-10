#include "BloodVfx.h"
#include "../Utils/Utils.h"

BloodVfx::BloodVfx()
{
}

void BloodVfx::Init(Vector2f playerPos)
{
	sprite.setPosition(playerPos);
	animation.SetTarget(&sprite);
	animation.AddClip("blood_vfx");
	animation.Play("blood_vfx");
}

void BloodVfx::Update(float dt)
{
	animation.Update(dt);
	Utils::SetOrigin(sprite, Pivots::Center);
}

void BloodVfx::Draw(RenderWindow& window)
{
	if (animation.IsAnimationEnd()) return;
	window.draw(sprite);
}

BloodVfx::~BloodVfx()
{
}
