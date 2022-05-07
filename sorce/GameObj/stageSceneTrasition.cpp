#include "stageSceneTrasition.h"
#include "../Resource/TextureHolder.h"
#include "../Utils/Utils.h"

stageSceneTrasition::stageSceneTrasition()
	:height(0), opacity(0), active(false)
{

}

void stageSceneTrasition::Init(Vector2i res)
{
	sprite.setTexture(TextureHolder::GetTexture("Sprite/dialogueBG_hell.png"));
	Utils::SetOrigin(sprite, Pivots::Center);
	resolution = res;
	bg.setSize(Vector2f((int)resolution.x, (int)resolution.y));
	bg.setFillColor(Color::Transparent);
	active = false;
	height = 0;
	opacity = 0;
}

void stageSceneTrasition::Update(float dt)
{
	bg.setFillColor(Color{ 0, 0, 0, (Uint8)opacity });
	sprite.setTextureRect({ 0, (int)((544.f - height) * 0.5f), resolution.x, (int)height});
	Utils::SetOrigin(sprite, Pivots::Center);
	sprite.setPosition(resolution.x * 0.5f, resolution.y * 0.4f);

	if (height >= 544)
	{
		bg.setFillColor(Color::Black);
	}
	else
	{
		if (opacity < 255)
		{
			opacity += dt;
		}
		else
		{
			bg.setFillColor(Color::Black);
		}

		height += dt * 2.5f;
	}
}

void stageSceneTrasition::Draw(RenderWindow& window)
{
	window.draw(bg);
	window.draw(sprite);
}

void stageSceneTrasition::Avtivate()
{
	active = true;
}
