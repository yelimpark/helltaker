#include "BloodVfx.h"
#include "../Utils/Utils.h"

BloodVfx::BloodVfx()
	:useable(true)
{
}

void BloodVfx::Init(Vector2f playerPos)
{	
	if (!useable || position == playerPos) return;
	useable = false;
	position = playerPos;
	sprite.setPosition(position);
	animation.SetTarget(&sprite);
	animation.AddClip("blood_vfx");
	animation.Play("blood_vfx");
}

void BloodVfx::Update(float dt)
{
	if (animation.IsAnimationEnd()) {
		useable = true;
		return;
	}
	else
	{
		animation.Update(dt);
		Utils::SetOrigin(sprite, Pivots::Center);
	}
}

void BloodVfx::Draw(RenderWindow& window)
{
	if (animation.IsAnimationEnd()) return;
	window.draw(sprite);
}

BloodVfx::~BloodVfx()
{
}
