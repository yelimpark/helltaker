#include "ScriptWithChoice.h"
#include "../Resource/ResorceHolder.h"
#include "../Utils/InputManager.h"

ScriptWithChoice::ScriptWithChoice()
	:cursor(0)
{
}

void ScriptWithChoice::Init(LevelEndngData& data, Vector2i resolution, OptionData& option1Data, OptionData& option2Data)
{
	cursor = 0;
	character.setTexture(TextureHolder::GetTexture(data.characterFileName));
	//Utils::SetOrigin(character, Pivots::CenterBottom);

	name.setFont(FontHolder::GetFont("Font/CrimsonPro-Medium.ttf"));
	name.setString(data.name);
	name.setCharacterSize(40);
	name.setFillColor(Color{ 230,77,81 });
	name.setPosition(resolution.x * 0.5, 900.f);

	option[0].Init(option1Data, Vector2f(500, 200));
	option[0].SetActive(true);
	option[1].Init(option2Data, Vector2f(500, 300));
}

UpdateOutput ScriptWithChoice::Update(float dt)
{
	if (InputManager::GetKeyDown(Keyboard::Up)) {
		cursor = 0;
		option[0].SetActive(true);
		option[1].SetActive(false);
	}
	if (InputManager::GetKeyDown(Keyboard::Down)) {
		cursor = 1;
		option[0].SetActive(false);
		option[1].SetActive(true);
	}
	if (InputManager::GetKeyDown(Keyboard::Enter)) {
		if (option[cursor].IsBad()) {
			return UpdateOutput::BADEND;
		}
		return UpdateOutput::SKIP;
	}
	return UpdateOutput::HOLD;
}

void ScriptWithChoice::Draw(RenderWindow& window)
{
	window.draw(character);
	window.draw(line);
	window.draw(name);
	option[0].Draw(window);
	option[1].Draw(window);
}