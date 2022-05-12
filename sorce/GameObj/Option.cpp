#include "Option.h"
#include "../Resource/ResorceHolder.h"
#include "../Utils/Utils.h"

Option::Option()
	:active(false), isBad(false)
{
}

void Option::Init(OptionData& data, Vector2f pos)
{
	sprite.setTexture(TextureHolder::GetTexture("Sprite/button0004.png"));
	Utils::SetOrigin(sprite, Pivots::Center);
	sprite.setPosition(pos);

	text.setFont(FontHolder::GetFont("Font/CrimsonPro-Medium.ttf"));
	text.setString(data.line);
	Utils::SetOrigin(text, Pivots::Center);
	text.setPosition(pos.x, pos.y-7.f);
	sprite.setColor(Color{ 255, 255, 255, 100 });

	isBad = data.isBad;
}

void Option::SetActive(bool active)
{
	this->active = active;
	
	if (active) {
		sprite.setTexture(TextureHolder::GetTexture("Sprite/button0003.png"));
		Utils::SetOrigin(sprite, Pivots::Center);
		sprite.setColor(Color{ 230,77,81 });
		sprite.setScale(1.05f, 1.05f);
		text.setScale(1.05f, 1.05f);
	}
	else {
		sprite.setTexture(TextureHolder::GetTexture("Sprite/button0004.png"));
		Utils::SetOrigin(sprite, Pivots::Center);
		sprite.setColor(Color{ 255, 255, 255, 100 });
		sprite.setScale(1.f, 1.f);
		text.setScale(1.f, 1.f);
	}
}

void Option::Draw(RenderWindow& window)
{
	window.draw(sprite);
	window.draw(text);
}

bool Option::IsBad()
{
	return isBad;
}
