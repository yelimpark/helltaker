#include "FlameBase.h"
#include "../Resource/TextureHolder.h"
#include <iostream>

FlameBase::FlameBase()
	:position(0, 0)
{

}

void FlameBase::Init(float x, float y)
{
	sprite.setTexture(TextureHolder::GetTexture("Sprite/FLAMEbase0001.png"));

	position.x = x;
	position.y = y;
	sprite.setPosition(position);
}

void FlameBase::Draw(RenderWindow& window)
{
	window.draw(sprite);
}
