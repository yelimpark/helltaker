#include "ScriptWithChoice.h"
#include "../Resource/ResorceHolder.h"
#include "../Utils/InputManager.h"
#include "../Utils/Utils.h"

ScriptWithChoice::ScriptWithChoice()
	:cursor(0)
{
}

void ScriptWithChoice::Init(LevelEndngData& data, Vector2i resolution, OptionData& option1Data, OptionData& option2Data)
{
	cursor = 0;
	Script::Init(data, resolution);

	option[0].Init(option1Data, Vector2f(resolution.x * 0.5, 900));
	option[0].SetActive(true);
	option[1].Init(option2Data, Vector2f(resolution.x * 0.5, 1000));
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
		std::cout << option[cursor].IsBad() << std::endl;
		if (option[cursor].IsBad()) {
			return UpdateOutput::BADEND;
		}
		return UpdateOutput::SKIP;
	}
	return UpdateOutput::HOLD;
}

void ScriptWithChoice::Draw(RenderWindow& window)
{
	Script::Draw(window);
	option[0].Draw(window);
	option[1].Draw(window);
}

ScriptWithChoice::~ScriptWithChoice()
{
}
