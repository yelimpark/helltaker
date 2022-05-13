#include "Key.h"
#include "./MapCode.h"
#include "../Utils/Utils.h"


void Key::Init(Vector2f pos, int tileSize)
{
	position = pos;
	sprite.setPosition(position);
	vfxSprite.setPosition(position);

	animation.SetTarget(&sprite);
	animation.AddClip("Key");
	animation.Play("Key");

	vfxAnimation.SetTarget(&vfxSprite);
	vfxAnimation.AddClip("huge_vfx");
	vfxAnimation.Play("huge_vfx");

	this->tileSize = tileSize;

	isEarned = false;
	isActive = true;
}

void Key::Update(float dt)
{
	animation.Update(dt);
	Utils::SetOrigin(sprite, Pivots::Center);
	if (isActive)	{
		if (isEarned) {
			if (vfxAnimation.IsAnimationEnd()) {
				isActive = false;
			}
			else {
				vfxAnimation.Update(dt);
				Utils::SetOrigin(vfxSprite, Pivots::Center);
			}
		}
	}

}

void Key::Draw(RenderWindow& window)
{
	window.draw(sprite);
	if (isEarned) {
		if (!isActive) return;
		window.draw(vfxSprite);
	}
}

void Key::Clear()
{
	sprite.setPosition(2000, 1500);
}

bool Key::IsCapturedPlayer(char**& map, int tileSize)
{
	int idxY = (int)position.y / tileSize;
	int idxX = (int)position.x / tileSize;

	if (map[idxY][idxX] == (char)MapCode::PLAYER && isActive)
	{
		isEarned = true;
	}
	return isEarned;
}

Vector2f Key::GetKeyPos()
{
	return position;
}
