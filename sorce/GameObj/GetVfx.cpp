#include "GetVfx.h"
#include "../Utils/Utils.h"

void GetVfx::Init(Vector2f playerPos)
{
	sprite.setPosition(playerPos);
	animation.SetTarget(&sprite);
}

void GetVfx::GetItem()
{
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
	window.draw(sprite);
}
