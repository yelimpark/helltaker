#include "stageSceneTrasition.h"
#include "../Resource/TextureHolder.h"
#include "../Utils/Utils.h"

stageSceneTrasition::stageSceneTrasition()
	:height(0), opacity(0), active(false)
{

}

void stageSceneTrasition::Init(Vector2i res)
{
	active = false;
	height = 0;
	opacity = 0;
	resolution = res;
	
	sprite.setTexture(TextureHolder::GetTexture("Sprite/dialogueBG_hell.png"));
	Utils::SetOrigin(sprite, Pivots::Center);
	sprite.setPosition(resolution.x * 0.5f, resolution.y * 0.4f);
	sprite.setTextureRect({ 0, (int)((HEIGHT_MAX - height) * 0.5f), resolution.x, (int)height });

	bg.setSize(Vector2f((int)resolution.x, (int)resolution.y));
	bg.setFillColor(Color::Transparent);
}

void stageSceneTrasition::Update(float dt)
{
	if (!active) return;
	if (height >= HEIGHT_MAX)
	{
		height = HEIGHT_MAX;
		bg.setFillColor(Color(2, 2, 27));
		return;
	}

	bg.setFillColor(Color{ 0, 0, 0, (Uint8)opacity });
	
	sprite.setTextureRect({ 0, (int)((HEIGHT_MAX - height) * 0.5f), resolution.x, (int)height});
	Utils::SetOrigin(sprite, Pivots::Center);

	opacity += OPACITY_MAX * dt;
	height += HEIGHT_MAX * dt;
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
