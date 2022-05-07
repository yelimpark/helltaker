#include "Skull.h"

void Skull::Init(float x, float y)
{
	position.x = x;
	position.y = y;

	sprite.setPosition(position);

	animation.SetTarget(&sprite);
	animation.AddClip("SkullStand");
	animation.AddClip("SkullPushed");

	animation.Play("SkullStand");
}

void Skull::Update(float dt)
{
	animation.Update(dt);
	sprite.setOrigin(sprite.getGlobalBounds().width * 0.5f, sprite.getGlobalBounds().height * 0.5f);
}

void Skull::OnPushed()
{
	animation.Play("SkullPushed");
	animation.PlayQue("SkullStand");
}

void Skull::OnHitted()
{
	isDead = true;
}

void Skull::Draw(RenderWindow& window)
{
	window.draw(sprite);
}
