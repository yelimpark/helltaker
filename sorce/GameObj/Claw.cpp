#include "Claw.h"
#include "../Resource/TextureHolder.h"
#include "../Utils/Utils.h"

void Claw::Init()
{
	sprite.setTexture(TextureHolder::GetTexture("Sprite/assets100V20116.png"));
	sprite.setPosition(position);

	animation.SetTarget(&sprite);
	animation.AddClip("ActivateClaw"); //20-23
	animation.AddClip("DectivateClaw"); //16-20

	sprite.setPosition(980, 600);
}

void Claw::Update(float dt)
{
	animation.Update(dt);
	Utils::SetOrigin(sprite, Pivots::Center);
}

void Claw::ActivateClaw()
{
	animation.Play("ActivateClaw");
}

void Claw::DeactivateClaw()
{
}

void Claw::Draw(RenderWindow& window)
{
	window.draw(sprite);
}

bool Claw::IsActive()
{
	return isActive;
}
