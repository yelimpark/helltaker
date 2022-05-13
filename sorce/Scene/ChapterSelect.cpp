#include "ChapterSelect.h"
#include "../Framework/Framework.h"
#include "../Scene/Scene.h"
#include "../Utils/SceneManager.h"
#include "../Utils/InputManager.h"
#include "../GameObj/MapCode.h"
#include "../Utils/Utils.h"
#include "../Utils/rapidcsv.h"

#include "../GameObj/Flame.h"
#include "../GameObj/MapCode.h"

#include <sstream>
#include <algorithm>
#include <map>


void ChapterSelect::InitLevel()
{
	std::map<std::string, LevelData> levelDatas;
	Utils::CsvToStruct<LevelData>(levelDatas, "./LevelInfo/LevelInfo.csv");

	//chapters에 csv chapter전체가 들어가게됨
	for (int i = 1; i < levelDatas.size() + 1; ++i)
	{
		stringstream ss;
		ss << i;
		chapters.push_back(levelDatas[ss.str()].chapter);
	}

	//chapters에 데이터가 삽입되어있음 
	//배열에 넣어줄때 동적할당 사용

	text.setString(chapters[0]);
	text.setFont(FontHolder::GetFont("Font/CrimsonPro-Medium.ttf"));
	text.setCharacterSize(30);
	text.setFillColor(Color{ 255, 255, 255, 225 });
	Utils::SetOrigin(text, Pivots::Center);
	text.setPosition(Vector2f(
		static_cast<float>(window.getSize().x / 2.5f),
		static_cast<float>(window.getSize().y / 8.f + 720))
	);

	char format[] = "Sprite/%02d.png";
	char buffer[128];
	for (int i = 0; i < chapters.size(); ++i)
	{
		sprintf_s(buffer, format, i + 1);
		romenum[i].setTexture(TextureHolder::GetTexture(buffer));
		Utils::SetOrigin(romenum[i], Pivots::Center);
		romenum[i].setColor({ 255, 255, 255, 128 });
		romenum[i].setPosition(Vector2f(
			static_cast<float>(window.getSize().x / 15.72f * i + 408),
			static_cast<float>(window.getSize().y / 8.f * 0.5f + 700))
		);
	}

}

ChapterSelect::ChapterSelect(SceneManager& sceneManager)
	:Scene(sceneManager), selectChapter(0), level(GameVal::level)
{
	GameVal::level = level;
	InitLevel();
	bg.setTexture(TextureHolder::GetTexture("Sprite/background.png"));

	lineImg[0].setTexture(TextureHolder::GetTexture("Sprite/W_chapterSelect.png"));
	lineImg[1].setTexture(TextureHolder::GetTexture("Sprite/W_chapterSelect_s.png"));
	for (int i = 0; i < 2; i++) {
		lineImg[0].setColor({ 255, 255, 255, 255 });
		Utils::SetOrigin(lineImg[i], Pivots::Center);
		lineImg[i].setPosition(Vector2f(
			static_cast<float>(window.getSize().x / 2.f),
			static_cast<float>(window.getSize().y / 8.f * i + 700))
		);
	}
	for (int i = 0; i < MAX_NUMBER_OF_CHAPTER; i++) {
		img[i].setTexture(TextureHolder::GetTexture("Sprite/W_chapter1.png"));
		Utils::SetOrigin(img[i], Pivots::Center);
		img[i].setColor({ 255, 255, 255, 128 });
		img[i].setPosition(Vector2f(
			static_cast<float>(window.getSize().x / 15.72f * i + 408),
			static_cast<float>(window.getSize().y / 8.f * 0.5f + 700))
		);
	}
	rec.setTexture(TextureHolder::GetTexture("Sprite/W_chapter2.png"));
	Utils::SetOrigin(rec, Pivots::Center);
	rec.setColor({ 255, 255, 255, 128 });
	rec.setPosition(Vector2f(
		static_cast<float>(window.getSize().x / 15.72f * 0 + 408),
		static_cast<float>(window.getSize().y / 8.f * 0.5f + 700))
	);

}

void ChapterSelect::Init()
{
	MovingMenu();
	selectChapter = 0;
	MovingMenuchange();
}

void ChapterSelect::MovingMenu()
{
	text.setString(chapters[selectChapter]);
	Utils::SetOrigin(text, Pivots::Center);
	img[selectChapter].setColor({ 255, 255, 255, 128 });
	rec.setPosition(Vector2f(
		static_cast<float>(window.getSize().x / 15.72f * selectChapter + 408),
		static_cast<float>(window.getSize().y / 8.f * 0.5f + 700))
	);
}

void ChapterSelect::MovingMenuchange()
{
	text.setString(chapters[selectChapter]);
	Utils::SetOrigin(text, Pivots::Center);
	img[selectChapter].setColor({ 255, 255, 255, 225 });
	rec.setPosition(Vector2f(
		static_cast<float>(window.getSize().x / 15.72f * selectChapter + 408),
		static_cast<float>(window.getSize().y / 8.f * 0.5f + 700))
	);
}

void ChapterSelect::Update(Time& dt)
{

	if (InputManager::GetKeyDown(Keyboard::Right))
	{
		MoveRight();
	}
	if (InputManager::GetKeyDown(Keyboard::Left))
	{
		MoveLeft();
	}
	if (InputManager::GetKeyDown(Keyboard::Enter))
	{
		Init();
		//===============================GameVal data==========================
		selectChapter = level;
		//=====================================================================
		switch (GetPressChapter())
		{
		case 0:
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
			break;
		}
	}
}

void ChapterSelect::MoveLeft()
{

	if (selectChapter - 1 >= 0)
	{
		MovingMenu();
		selectChapter--;
		if (selectChapter == -1) {
			selectChapter = 2;
		}
		//====================================색변화 테스트==========================
		if (selectChapter == 10) {
			text.setFillColor(Color{ 230,77,81, 225 });
			img[selectChapter].setColor(Color{ 230,77,81, 225 });
		}
		else {
			text.setFillColor(Color{ 255, 255, 255, 225 });
			img[selectChapter].setColor(Color{ 255, 255, 255, 225 });
		}
		//====================================색변화 테스트==========================
		MovingMenuchange();
	}
}

void ChapterSelect::MoveRight()
{
	if (selectChapter + 1 < MAX_NUMBER_OF_CHAPTER)
	{
		MovingMenu();
		selectChapter++;
		if (selectChapter == 11) {
			selectChapter = 0;
		}
		//====================================색변화 테스트==========================
		if (selectChapter == 10) {
			text.setFillColor(Color{ 230,77,81, 225 });
			img[selectChapter].setColor(Color{ 230,77,81, 225 });
		}
		else {
			text.setFillColor(Color{ 255, 255, 255, 225 });
			img[selectChapter].setColor(Color{ 255, 255, 255, 225 });
		}
		//====================================색변화 테스트=========================
		MovingMenuchange();
	}
}

int ChapterSelect::GetPressChapter()
{
	return selectChapter;

}

void ChapterSelect::Render()
{
	window.draw(bg);
	for (int i = 0; i < 2; i++) {
		window.draw(lineImg[i]);
	}
	for (int i = 0; i < MAX_NUMBER_OF_CHAPTER; i++) {
		window.draw(img[i]);
	}
	window.draw(rec);
	for (int i = 0; i < 12; i++) {
		window.draw(romenum[i]);
	}
	window.draw(text);

}

void ChapterSelect::Release()
{
}

ChapterSelect::~ChapterSelect()
{
	Release();
}