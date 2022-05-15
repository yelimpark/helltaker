#include "BoneParticle.h"
#include "../Utils/Utils.h"

BoneParticle::BoneParticle()
{
}

void BoneParticle::Init(Vector2f pos)
{
	sprite.setPosition(pos);
	animation.SetTarget(&sprite);
	animation.AddClip("SkullCrushed");
	animation.Play("SkullCrushed");
	soundEffects.SoundEffectPlay("Sound/enemy_die_01.wav");
}

void BoneParticle::Update(float dt)
{
	if (animation.IsAnimationEnd()) return;
	animation.Update(dt);
	Utils::SetOrigin(sprite, Pivots::Center);
}

void BoneParticle::Draw(RenderWindow& window)
{
	if (animation.IsAnimationEnd()) return;
	window.draw(sprite);
}

BoneParticle::~BoneParticle()
{
}
