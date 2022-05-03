#pragma once
#include "./Scene.h"
#include "../UI/StageUI.h"
#include <list>
#include <iostream>

struct LevelData {
	std::string BgFilename;
	int BgPosX;
	int BgPosY;

	LevelData() {};

	LevelData(std::vector<std::string>& row) {
		BgFilename = row[1];
		BgPosX = stoi(row[2]);
		BgPosY = stoi(row[3]);
	};
};

struct FlameData {
	int x;
	int y;

	FlameData(std::vector<std::string>& row) {
		x = stoi(row[1]);
		y = stoi(row[2]);
	};
};

class StageScene : public Scene
{
private:
	StageUI ui;

	int level;
	std::map<std::string, LevelData> levelDatas;
	std::map<std::string, std::vector<FlameData>> flameDatas;
	
	Sprite spriteBackground;
	Sprite spriteSide1;
	Sprite spriteSide2;
	Sprite flameBase1;
	Sprite flameBase2;
	Sprite transition;

	int lastTurn;
	float transHeight;

	bool transeScene;

	View uiView;

public:
	StageScene(SceneManager& sceneManager);
	virtual void Init();
	virtual void Update(Time& dt);
	virtual void Render();
	virtual void Release();
	void TranseScene(float dt);
	virtual ~StageScene();
};

