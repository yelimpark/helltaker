#include "Skull.h"

void Skull::Init(float x, float y)
{
	position.x = x;
	position.y = y;

	sprite.setPosition(position);

	animation.SetTarget(&sprite);
	animation.AddClip("Skull");
	animation.Play("Skull");
}

void Skull::Update(float dt)
{
	animation.Update(dt);
	sprite.setOrigin(sprite.getGlobalBounds().width * 0.5f, sprite.getGlobalBounds().height * 0.5f);
}

void Skull::Draw(RenderWindow& window)
{
	window.draw(sprite);
}
