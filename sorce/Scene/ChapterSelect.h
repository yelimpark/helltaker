#pragma once
#include "./Scene.h"
#include "../Resource/AnimationController.h"
#include "../GameObj/booper.h"
#include "../SceneInitializer/StageSceneInitializer.h"
#include "../GameObj/SoundEffect.h"
#include <vector>

#define MAX_NUMBER_OF_CHAPTER 11

class ChapterSelect : public Scene
{
private:


	std::map<std::string, LevelData> levelDatas;

	Text text;
	std::vector<std::string> chapters;

	Sprite romenum[12];

	RectangleShape rectangle[MAX_NUMBER_OF_CHAPTER];

	Sprite img[MAX_NUMBER_OF_CHAPTER];
	Sprite rec;
	Sprite num[MAX_NUMBER_OF_CHAPTER];
	Sprite lineImg[2];
	Sprite bg;

	int level;
	int selectChapter;

public:

	ChapterSelect(SceneManager& sceneManager);

	virtual void Init();

	virtual void MovingMenu();

	virtual void MovingMenuchange();

	virtual void InitLevel();

	virtual void Update(Time& dt);

	virtual void MoveLeft();

	virtual void MoveRight();

	virtual int GetPressChapter();

	virtual void Render();

	virtual void Release();

	virtual ~ChapterSelect();

};
