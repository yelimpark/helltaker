#include "CutSceneTransition.h"
#include "../Utils/Utils.h"

void CutSceneTransition::Init()
{
	animation.SetTarget(&sprite);
	animation.AddClip("CutTransition");
	Utils::SetOrigin(sprite, Pivots::CenterBottom);
	soundEffects.SoundEffectPlay("Sound/screen_changer_part1_01.wav");
	sprite.setPosition(Vector2f(1920 * 0.5f, 1080));
	animation.Play("CutTransition");
}

bool CutSceneTransition::Update(float dt)
{
	animation.Update(dt);
	Utils::SetOrigin(sprite, Pivots::CenterBottom);
	return animation.IsAnimationEnd();
}

void CutSceneTransition::Draw(RenderWindow& window)
{
	window.draw(sprite);
}

bool CutSceneTransition::IsFull()
{
	soundEffects.SoundEffectPlay("Sound/screen_changer_part2_01.wav");
	return animation.OnFrame(20);
}
