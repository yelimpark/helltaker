#include "MoveVfx.h"
#include "../Utils/Utils.h"

MoveVfx::MoveVfx()
{
}

void MoveVfx::Init(Vector2f pos)
{
	sprite.setPosition(pos);
	sprite.setColor(Color{ 255, 255, 255, 100 });
	animation.SetTarget(&sprite);
	animation.AddClip("small_vfx2");
	animation.Play("small_vfx2");
}

void MoveVfx::Update(float dt)
{
	if (animation.IsAnimationEnd()) return;
	animation.Update(dt);
	Utils::SetOrigin(sprite, Pivots::Center);
}

void MoveVfx::Draw(RenderWindow& window)
{
	if (animation.IsAnimationEnd()) return;
	window.draw(sprite);
}
