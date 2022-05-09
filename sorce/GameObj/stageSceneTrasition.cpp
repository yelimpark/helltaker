#include "stageSceneTrasition.h"
#include "../Resource/TextureHolder.h"
#include "../Utils/Utils.h"

stageSceneTrasition::stageSceneTrasition()
	:height(0), opacity(0)
{

}

void stageSceneTrasition::Init(Vector2i res)
{
	height = 0;
	opacity = 0;
	resolution = res;
	
	sprite.setTexture(TextureHolder::GetTexture("Sprite/dialogueBG_hell.png"));
	Utils::SetOrigin(sprite, Pivots::Center);
	sprite.setPosition(resolution.x * 0.5f, resolution.y * 0.4f);
	sprite.setTextureRect({ 0, (int)((HEIGHT_MAX - height) * 0.5f), resolution.x, (int)height });

	fadeOut.setSize(Vector2f((int)resolution.x, (int)resolution.y));
	fadeOut.setFillColor(Color::Transparent);
}

bool stageSceneTrasition::OnClear(float dt)
{
	if (height >= HEIGHT_MAX)
	{
		height = HEIGHT_MAX;
		fadeOut.setFillColor(Color(2, 2, 27));
		return true;
	}

	fadeOut.setFillColor(Color{ 2, 2, 27, (Uint8)opacity });

	//Utils::SetOrigin(sprite, Pivots::Center);
	sprite.setTextureRect({ 0, (int)((HEIGHT_MAX - height) * 0.5f), resolution.x, (int)height});


	opacity += OPACITY_MAX * dt;
	height += HEIGHT_MAX * dt;
	return false;
}

void stageSceneTrasition::Draw(RenderWindow& window)
{
	window.draw(fadeOut);
	window.draw(sprite);
}