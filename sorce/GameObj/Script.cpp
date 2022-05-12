#include "Script.h"
#include "../Resource/ResorceHolder.h"
#include "../Utils/Utils.h"
#include <sstream>

Script::Script()
{
}

void Script::Init(LevelEndngData& data, Vector2i resolution)
{
	Release();

	character.setTexture(TextureHolder::GetTexture(data.characterFileName));
	Utils::SetOrigin(character, Pivots::CenterBottom);
	character.setPosition(resolution.x * 0.5, 700);

	name.setFont(FontHolder::GetFont("Font/CrimsonPro-Medium.ttf"));
	name.setString(data.name);
	name.setCharacterSize(40);
	name.setFillColor(Color{ 230,77,81 });
	name.setPosition(resolution.x * 0.5, 720.f);
	Utils::SetOrigin(name, Pivots::Center);

	std::istringstream iss(data.line);
	float top = 780.f;
	int idx = 0;
	std::string token;
	while (getline(iss, token, '-')) {
		Text* text = new Text();
		text->setString(token);
		text->setFont(FontHolder::GetFont("Font/CrimsonPro-Medium.ttf"));
		text->setFillColor(Color::White);
		Utils::SetOrigin(*text, Pivots::Center);
		text->setPosition(resolution.x * 0.5, top + 40.f * idx);
		texts.push_back(text);
		++idx;
	}

}

void Script::Draw(RenderWindow& window)
{
	window.draw(character);
	for (auto& text : texts) {
		window.draw(*text);
	}
	window.draw(name);
}

void Script::Release()
{
	for (auto& text : texts) {
		if (text != nullptr)
			delete text;
	}
	texts.clear();
}

Script::~Script()
{
	Release();
}
