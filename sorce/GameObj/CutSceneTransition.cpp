#include "CutSceneTransition.h"
#include "../Utils/Utils.h"

void CutSceneTransition::Init()
{
	animation.SetTarget(&sprite);
	animation.AddClip("CutTransition");
}

void CutSceneTransition::Update(float dt)
{
	animation.Play("CutTransition");
	animation.Update(dt);
	Utils::SetOrigin(sprite, Pivots::CenterBottom);
	sprite.setPosition(Vector2f(1920 * 0.5f, 1080));
}

void CutSceneTransition::Draw(RenderWindow& window)
{
	window.draw(sprite);
}
