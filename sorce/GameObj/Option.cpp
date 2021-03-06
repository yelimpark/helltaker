#include "Option.h"
#include "../Resource/ResorceHolder.h"
#include "../Utils/Utils.h"
#include "../Utils/GameVal.h"

Option::Option()
	:active(false)
{
}
void Option::Init(OptionData& data, Vector2f pos)
{
	nextNode = data.nextNode;

	sprite.setTexture(TextureHolder::GetTexture("Sprite/button0004.png"));
	Utils::SetOrigin(sprite, Pivots::Center);
	sprite.setPosition(pos);

	text.setFont(FontHolder::GetFont("Font/CrimsonPro-Medium.ttf"));
	if (GameVal::language.compare("Kor") == 0) {
		text.setFont(FontHolder::GetFont("Font/NotoSerifKR-Medium.otf"));
	}
	text.setString(Utils::s2w(data.line));
	Utils::SetOrigin(text, Pivots::Center);
	text.setPosition(pos.x, pos.y-7.f);
	sprite.setColor(Color{ 255, 255, 255, 100 });
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

bool Option::IsActive()
{
	return active;
}

std::string& Option::GetNextNode()
{
	return nextNode;
}
