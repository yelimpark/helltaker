#include "Flame.h"
#include "../Resource/TextureHolder.h"
#include "../Resource/AnimationHolder.h"
#include "../Utils/Utils.h"

#include <iostream>

Flame::Flame()
	:position(0, 0)
{

}

void Flame::Init(Vector2f pos)
{
	position = pos;
	sprite.setPosition(position);
	sprite.setScale(0.6f, 0.6f);
	sprite.setColor(Color::Yellow);

	animation.SetTarget(&sprite);
	animation.AddClip("Fire");
	animation.Play("Fire");
}

void Flame::Update(float dt)
{
	animation.Update(dt);
	Utils::SetOrigin(sprite, Pivots::Center);
	sprite.setOrigin(0, sprite.getGlobalBounds().height);
}

void Flame::Draw(RenderWindow& window)
{
	window.draw(sprite);
}
