#include "Death.h"
#include "../Utils/Utils.h"

Death::Death()
{
}

void Death::Init(Vector2f pos)
{
	sprite.setPosition(pos);
	animation.SetTarget(&sprite);
	animation.AddClip("dialogueDeath");
	animation.Play("dialogueDeath");
}

void Death::Update(float dt)
{
	if (animation.IsAnimationEnd()) return;
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
