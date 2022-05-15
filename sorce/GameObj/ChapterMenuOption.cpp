#include "ChapterMenuOption.h"
#include "../Utils/Utils.h"
#include "../Resource/TextureHolder.h"

ChapterMenuOption::ChapterMenuOption()
	:active(false)
{
}

void ChapterMenuOption::Init(std::string fileName, Vector2f pos)
{
	active = false;
	outline.setTexture(TextureHolder::GetTexture("Sprite/W_chapter1.png"));
	Utils::SetOrigin(outline, Pivots::Center);
	outline.setPosition(pos);

	inner.setTexture(TextureHolder::GetTexture("Sprite/W_chapter2.png"));
	Utils::SetOrigin(inner, Pivots::Center);
	inner.setPosition(pos);

	number.setTexture(TextureHolder::GetTexture(fileName));
	Utils::SetOrigin(number, Pivots::Center);
	number.setPosition(pos);
}

void ChapterMenuOption::SetActive(bool active)
{
	this->active = active;

	if (active) {
		outline.setColor(Color{ 255, 255, 255, 255 });
		inner.setColor(Color{ 255, 255, 255, 150 });
		number.setColor(Color{ 255, 255, 255, 255 });
	}
	else {
		outline.setColor(Color{ 255, 255, 255, 100 });
		inner.setColor(Color{ 255, 255, 255, 0 });
		number.setColor(Color{ 255, 255, 255, 100 });
	}
}

void ChapterMenuOption::Draw(RenderWindow& window)
{
	window.draw(outline);
	window.draw(inner);
	window.draw(number);
}

ChapterMenuOption::~ChapterMenuOption()
{
}
