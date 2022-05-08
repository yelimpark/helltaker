#include "CutSceneTransition.h"
#include "../Utils/Utils.h"

void CutSceneTransition::Init()
{
	animation.SetTarget(&sprite);
	animation.AddClip("CutTransition");
	Utils::SetOrigin(sprite, Pivots::CenterBottom);
	sprite.setPosition(Vector2f(1920 * 0.5f, 1080));
	animation.Play("CutTransition");
	isFull = false;
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
	if (animation.OnFrame(20)) isFull = true;

	return isFull;
}
