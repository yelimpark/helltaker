#include "Success.h"
#include "../Utils/Utils.h"


Success::Success()
{
}

void Success::Init(Vector2f pos)
{
	sprite.setPosition(pos);
	animation.SetTarget(&sprite);
	animation.AddClip("success_all");
	animation.Play("success_all");
}

void Success::Update(float dt)
{
	animation.Update(dt);
	soundEffects.SoundEffectPlay("Sound/dialogue_success_01.wav");
	Utils::SetOrigin(sprite, Pivots::Center);
}

void Success::Draw(RenderWindow& window)
{

	if (animation.IsAnimationEnd()) return;
	window.draw(sprite);
}


Success::~Success()
{
}
