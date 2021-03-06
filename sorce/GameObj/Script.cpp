#include "Script.h"
#include "../Resource/ResorceHolder.h"
#include "../Utils/Utils.h"
#include "../Utils/GameVal.h"
#include <sstream>

Script::Script()
	:nextNode("")
{
}

std::string w2s(const std::wstring& var)
{
	static std::locale loc("");
	auto& facet = std::use_facet<std::codecvt<wchar_t, char, std::mbstate_t>>(loc);
	return std::wstring_convert<std::remove_reference<decltype(facet)>::type, wchar_t>(&facet).to_bytes(var);
}

void Script::Init(CutSceneData& data, Vector2i resolution)
{
	Release();

	nextNode = data.nextNode;

	background.setTexture(TextureHolder::GetTexture(data.backgroundFileName));
	Utils::SetOrigin(background, Pivots::CenterBottom);
	background.setPosition(resolution.x * 0.5, 700);

	character.setTexture(TextureHolder::GetTexture(data.characterFileName));
	Utils::SetOrigin(character, Pivots::CenterBottom);
	character.setPosition(resolution.x * 0.5, 700);

	name.setFont(FontHolder::GetFont("Font/CrimsonPro-Medium.ttf"));
	if (GameVal::language.compare("Kor") == 0) {
		name.setFont(FontHolder::GetFont("Font/NotoSerifKR-Medium.otf"));
	}
	name.setString(Utils::s2w(data.name));
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
		text->setFont(FontHolder::GetFont("Font/CrimsonPro-Medium.ttf"));
		if (GameVal::language.compare("Kor") == 0) {
			text->setFont(FontHolder::GetFont("Font/NotoSerifKR-Medium.otf"));
		}
		text->setString(Utils::s2w(token));
		text->setFillColor(Color::White);
		Utils::SetOrigin(*text, Pivots::Center);
		text->setPosition(resolution.x * 0.5, top + 40.f * idx);
		texts.push_back(text);
		++idx;
	}

}

void Script::Draw(RenderWindow& window)
{
	window.draw(background);
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

std::string& Script::GetNextNode()
{
	return nextNode;
}
