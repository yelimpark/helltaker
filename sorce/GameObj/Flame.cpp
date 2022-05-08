#include "Flame.h"
#include "../Resource/TextureHolder.h"
#include "../Resource/AnimationHolder.h"
#include "../Utils/Utils.h"

Flame::Flame()
{

}

void Flame::Init(Vector2f pos)
{
	sprite.setPosition(pos);
	sprite.setScale(0.6f, 0.6f);
	sprite.setColor(Color(228, 193, 101));

	animation.SetTarget(&sprite);
	animation.AddClip("Fire");
	animation.Play("Fire");
}

void Flame::Update(float dt)
{
	animation.Update(dt);
	Utils::SetOrigin(sprite, Pivots::CenterBottom);
}

void Flame::Draw(RenderWindow& window)
{
	window.draw(sprite);
}
