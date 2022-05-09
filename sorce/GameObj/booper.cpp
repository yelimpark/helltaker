#include "booper.h"
#include "../Utils/Utils.h"

booper::booper()
{
}


void booper::Init(Vector2f pos)
{
	sprite.setPosition(pos);
	animation.SetTarget(&sprite);
	animation.AddClip("booper0006_s");
	animation.Play("booper0006_s");
}

void booper::Update(float dt)
{
	if (animation.IsAnimationEnd()) return;
	animation.Update(dt);
	Utils::SetOrigin(sprite, Pivots::Center);
}

void booper::Draw(RenderWindow& window)
{
	if (animation.IsAnimationEnd()) return;
	window.draw(sprite);
}

booper::~booper()
{
}
