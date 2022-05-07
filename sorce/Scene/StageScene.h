#pragma once
#include "./Scene.h"
#include "../UI/StageUI.h"
#include "../SceneInitializer/StageSceneInitializer.h"
#include "../GameObj/Player.h"
#include "../GameObj/Demon.h"
#include "../GameObj/stageSceneTrasition.h"
#include <vector>
#include "../GameObj/Skull.h"
#include <list>
#include <iostream>
#include "../GameObj/Box.h"

class Flame;
class Box;

class StageScene : public Scene
{
private:
	int level;
	char ** map;

	const int TILE_SIZE = 100; 
	const int LEFT_MARGINE = 10;
	const int TOP_MARGINE = 40;
	const float MOVE_SECOND = 0.1f;

	std::vector<Flame *> flames;
	std::vector<Sprite *> flameBases;
	std::vector<Box *> boxes;
	
	StageUI ui;

	Sprite Background;
	Sprite spriteSide1;
	Sprite spriteSide2;
	Player player;
	Demon demon;
	stageSceneTrasition transition;

	int lastTurn;

	bool isClear;

	void InitMap(std::string filepath, std::string level);

public:
	StageScene(SceneManager& sceneManager);

	virtual void Init();

	virtual void Update(Time& dt);

	virtual void Render();

	virtual void Release();

	virtual ~StageScene();

	int GetTileSize();
};