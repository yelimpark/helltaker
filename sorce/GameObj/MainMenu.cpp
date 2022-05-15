#include "MainMenu.h"
#include "../Utils/InputManager.h"
#include "../Resource/ResorceHolder.h"
#include "../Utils/Utils.h"

MainMenu::MainMenu()
	:cursor(0)
{
}

void MainMenu::Init(Vector2i resolution)
{
	OptionData optionDatas[3];
	optionDatas[0].line = "NEW GAME";
	optionDatas[1].line = "CHAPTER SELECT";
	optionDatas[2].line = "EXIT";

	int top = 800;
	for (int i = 0; i < OPTION_COUNT; i++) {
		options[i].Init(optionDatas[i], Vector2f(resolution.x * 0.5, top));
		top += 100;
	}

	name.setFont(FontHolder::GetFont("Font/CrimsonPro-Medium.ttf"));
	name.setString("Beelzebub, The Great Fly");
	name.setCharacterSize(40);
	name.setFillColor(Color{ 230,77,81 });
	name.setPosition(resolution.x * 0.5, 720.f);
	Utils::SetOrigin(name, Pivots::Center);

	cursor = 0;
	options[cursor].SetActive(true);
}

bool MainMenu::HandleInput(RenderWindow& window, SceneManager& sm)
{
	if (InputManager::GetKeyDown(Keyboard::Up) && cursor > 0) {
		options[cursor].SetActive(false);
		--cursor;
		soundEffect.SoundEffectPlay("Sound/button_menu_highlight_01.wav");
		options[cursor].SetActive(true);
	}
	if (InputManager::GetKeyDown(Keyboard::Down) && cursor < OPTION_COUNT - 1) {
		options[cursor].SetActive(false);
		++cursor;
		soundEffect.SoundEffectPlay("Sound/button_menu_highlight_01.wav");
		options[cursor].SetActive(true);
	}
	if (InputManager::GetKeyDown(Keyboard::Enter)) {
		soundEffect.SoundEffectPlay("Sound/button_menu_confirm_01.wav");
		switch (cursor)
		{
		case 0:
			GameVal::cutSceneIdx = 0;
			sm.ChangeScene(SceneType::CUT);
			break;

		case 1:
			return true;

		case 2:
			window.close();
			break;
		default:
			break;
		}
	}
	return false;
}

void MainMenu::Draw(RenderWindow& window)
{
	window.draw(name);
	for (int i = 0; i < OPTION_COUNT; i++) {
		options[i].Draw(window);
	}
}

MainMenu::~MainMenu()
{
}
