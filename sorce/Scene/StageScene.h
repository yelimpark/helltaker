#pragma once
#include <list>
#include <iostream>

#include "./Scene.h"
#include "../UI/StageUI.h"
#include "../GameObj/Box.h"

struct boxInfo
{
	std::string textureFilename;
	Vector2f position;
};


struct LevelData {
	std::string BgFilename;
	int BgPosX;
	int BgPosY;

	LevelData(std::vector<std::string>& row) {
		BgFilename = row[0];
		BgPosX = stoi(row[1]);
		BgPosY = stoi(row[2]);
	};
};

class StageScene : public Scene
{
private:
	StageUI ui;

	std::list<LevelData> levelDataList;
	int level;

	std::vector<boxInfo> boxdatas;

	Sprite spriteBackground;
	Sprite spriteSide1;
	Sprite spriteSide2;
	Sprite flameBase1;
	Sprite flameBase2;
	Sprite transition;

	RectangleShape transBack;

	int lastTurn;
	int opacity;
	float transHeight;
	
	std::vector<Box*> boxes;


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

