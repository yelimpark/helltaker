#include "FlameBase.h"
#include "../Resource/TextureHolder.h"
#include "../Resource/AnimationHolder.h"
#include "../Utils/Utils.h"

#include <iostream>

FlameBase::FlameBase()
	:position(0, 0)
{

}

void FlameBase::Init(float x, float y)
{
	baseSprite.setTexture(TextureHolder::GetTexture("Sprite/FLAMEbase0001.png"));

	position.x = x;
	position.y = y;
	baseSprite.setPosition(position);

	fireSprite.setPosition(Vector2f(position.x+8, position.y+6));
	animation.SetTarget(&fireSprite);

	animation.AddClip("Fire");

	animation.Play("Fire");
	fireSprite.setScale(0.6f, 0.6f);
	fireSprite.setColor(Color::Yellow);
}

void FlameBase::Update(float dt)
{
	animation.Update(dt);
	fireSprite.setOrigin(0, fireSprite.getGlobalBounds().height);
}

void FlameBase::Draw(RenderWindow& window)
{
	window.draw(baseSprite);
	window.draw(fireSprite);
}
