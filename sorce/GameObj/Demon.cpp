#include "Demon.h"
#include "../Resource/TextureHolder.h"

void Demon::Init(float x, float y)
{
	position.x = x;
	position.y = y;

	sprite.setPosition(position);

	animation.SetTarget(&sprite);
	animation.AddClip("Pandemonica");
	animation.Play("Pandemonica");

	heartYPos = 50.f;
	heart.setTexture(TextureHolder::GetTexture("Sprite/lovesign.png"));
}

void Demon::Update(float dt)
{
	animation.Update(dt);
	sprite.setOrigin(sprite.getGlobalBounds().width * 0.5f, sprite.getGlobalBounds().height * 0.5f);

	heart.setPosition(position.x - 55.f, position.y - heartYPos);

	static float dir = 1.f;
	if (heartYPos > 60)
	{
		dir = -1.f;
	}

	if (heartYPos <= 50)
	{
		dir = 1.f;
	}
	heartYPos += dir * dt * 50;


	
}

void Demon::Draw(RenderWindow& window)
{
	window.draw(sprite);
	window.draw(heart);
}
