#include "ChapterMenu.h"
#include "../Utils/Utils.h"
#include "../Utils/InputManager.h"
#include "../Resource/ResorceHolder.h"
#include "../SceneInitializer/StageSceneInitializer.h"

ChapterMenu::ChapterMenu()
	:cursor(0)
{
}

void ChapterMenu::Init(Vector2i resolution)
{
	topOutline.setTexture(TextureHolder::GetTexture("Sprite/W_chapterSelect.png"));
	Utils::SetOrigin(topOutline, Pivots::Center);
	topOutline.setPosition(resolution.x * 0.5, 780);

	bottomOutline.setTexture(TextureHolder::GetTexture("Sprite/W_chapterSelect.png"));
	Utils::SetOrigin(bottomOutline, Pivots::Center);
	bottomOutline.setScale(1.f, -1.f);
	bottomOutline.setPosition(resolution.x * 0.5, 920);

	text.setFont(FontHolder::GetFont("Font/CrimsonPro-Medium.ttf"));
	text.setPosition(resolution.x * 0.5, 960);

	std::map<std::string, LevelData> levelDatas;
	Utils::CsvToStruct<LevelData>(levelDatas, "./LevelInfo/LevelInfo.csv");


	int left = 400;
	for (int i = 1; i < levelDatas.size() + 1; ++i)
	{
		ChapterMenuOption* option = new ChapterMenuOption();
		option->Init(levelDatas[std::to_string(i)].chapImgPath, Vector2f(left, 850));
		option->SetActive(false);
		options.push_back(option);
		chapters.push_back(levelDatas[std::to_string(i)].chapter);
		left += 120;
	}

	cursor = 0;
	options[cursor]->SetActive(true);
	text.setString(chapters[cursor]);
	Utils::SetOrigin(text, Pivots::Center);
}

void ChapterMenu::HandleInput(SceneManager& sm)
{
	if (InputManager::GetKeyDown(Keyboard::Left) && cursor > 0) {
		options[cursor]->SetActive(false);
		--cursor;
		options[cursor]->SetActive(true);
		text.setString(chapters[cursor]);
		Utils::SetOrigin(text, Pivots::Center);
	}
	if (InputManager::GetKeyDown(Keyboard::Right) && cursor < options.size() - 1) {
		options[cursor]->SetActive(false);
		++cursor;
		options[cursor]->SetActive(true);
		text.setString(chapters[cursor]);
		Utils::SetOrigin(text, Pivots::Center);
	}
	if (InputManager::GetKeyDown(Keyboard::Enter)) {
		GameVal::level = cursor + 1;
		sm.ChangeScene(SceneType::STAGE, true);
	}
}

void ChapterMenu::Draw(RenderWindow& window)
{
	window.draw(text);
	for (auto& option : options) {
		option->Draw(window);
	}
	window.draw(topOutline);
	window.draw(bottomOutline);

}

void ChapterMenu::Release()
{
	for (auto& option : options) {
		if (option != nullptr)
			delete option;
	}
}

ChapterMenu::~ChapterMenu()
{
}
