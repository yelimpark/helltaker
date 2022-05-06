#include "Demon.h"

void Demon::Init(float x, float y)
{
	position.x = x;
	position.y = y;

	sprite.setPosition(position);

	animation.SetTarget(&sprite);
	animation.AddClip("Pandemonica");
	animation.Play("Pandemonica");
}

void Demon::Update(float dt)
{
	animation.Update(dt);
	sprite.setOrigin(sprite.getGlobalBounds().width * 0.5f, sprite.getGlobalBounds().height * 0.5f);
}

void Demon::Draw(RenderWindow& window)
{
	window.draw(sprite);
}
