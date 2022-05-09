#include "Death.h"
#include "../Utils/Utils.h"

Death::Death()
{
}

void Death::Init(Vector2f pos)
{
	sprite.setPosition(pos);
	animation.SetTarget(&sprite);
	animation.AddClip("dialogueDeathExport0002_s");
	animation.Play("dialogueDeathExport0002_s");
}

void Death::Update(float dt)
{
	animation.Update(dt);
	Utils::SetOrigin(sprite, Pivots::Center);
}

void Death::Draw(RenderWindow& window)
{
	if (animation.IsAnimationEnd()) return;
	window.draw(sprite);
}

Death::~Death()
{
}