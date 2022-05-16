#include "Claw.h"
#include "./MapCode.h"
#include "../Resource/TextureHolder.h"
#include "../Utils/Utils.h"
#include "../Utils/InputManager.h"

#include <iostream>


void Claw::Init(Vector2f pos)
{
	position = pos;
	sprite.setTexture(TextureHolder::GetTexture("Sprite/assets100V20116.png"));
	sprite.setPosition(position);

	animation.SetTarget(&sprite);
	animation.AddClip("ActivateClaw"); 
	animation.AddClip("DeactivateClaw"); 

	isActive = true;
}

bool Claw::Update(float dt, std::vector<Skull*>& skulls, Player& player)
{
	animation.Update(dt);
	Utils::SetOrigin(sprite, Pivots::Center);

	if (InputManager::GetKeyDown(Keyboard::Left) ||
		InputManager::GetKeyDown(Keyboard::Right) ||
		InputManager::GetKeyDown(Keyboard::Up) ||
		InputManager::GetKeyDown(Keyboard::Down))
	{
		if (!isActive)
		{
			animation.Play("ActivateClaw");
			isActive = true;
		}
		else
		{
			animation.Play("DeactivateClaw");
			isActive = false;
		}

		for (auto& skull : skulls) {
			if (skull->IsSkullHere(position)) {
				skull->Kill();
			}
		}

		Vector2i curIdx = Utils::PosToIdx(position);
		Vector2f playerPos = player.GetPos();

		if (Utils::PosToIdx(playerPos) == curIdx) {
			return true;
		}
	}

	return false;
}

void Claw::Draw(RenderWindow& window)
{
	window.draw(sprite);
}