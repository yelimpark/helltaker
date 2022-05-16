#include "ScriptWithChoice.h"
#include "../Resource/ResorceHolder.h"
#include "../Utils/InputManager.h"
#include "../Utils/Utils.h"

ScriptWithChoice::ScriptWithChoice()
{
}

void ScriptWithChoice::Init(CutSceneData& data, Vector2i resolution, OptionData& option1Data, OptionData& option2Data)
{
	Script::Init(data, resolution);

	option[0].Init(option1Data, Vector2f(resolution.x * 0.5, 900));
	option[0].SetActive(true);
	option[1].Init(option2Data, Vector2f(resolution.x * 0.5, 1000));
}

bool ScriptWithChoice::Update(float dt)
{
	if (InputManager::GetKeyDown(Keyboard::Up)) {
		soundEffects.SoundEffectPlay("Sound/button_dialogue_highlight_01.wav");
		option[0].SetActive(true);
		option[1].SetActive(false);
	}
	if (InputManager::GetKeyDown(Keyboard::Down)) {
		soundEffects.SoundEffectPlay("Sound/button_dialogue_highlight_01.wav");
		option[0].SetActive(false);
		option[1].SetActive(true);
	}
	if (InputManager::GetKeyDown(Keyboard::Enter)) {
		if (option[0].IsActive()) {
			nextNode = option[0].GetNextNode();
		}
		else {
			nextNode = option[1].GetNextNode();
		}
		return true;
	}
	return false;
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
