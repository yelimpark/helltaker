#pragma once
#include "./Scene.h"
#include "../UI/StageUI.h"
#include "../SceneInitializer/StageSceneInitializer.h"
#include "../GameObj/Player.h"
#include "../GameObj/Demon.h"
#include <vector>

class Flame;
class Box;

class StageScene : public Scene
{
private:
	StageUI ui;

	int level;
	char ** map;

	const int TILE_SIZE = 100; 
	const int LEFT_MARGINE = 10;
	const int TOP_MARGINE = 40;

	std::vector<Flame *> flames;
	std::vector<Sprite *> flameBases;
	std::vector<Box *> boxes;

	Sprite Background;
	Sprite spriteSide1;
	Sprite spriteSide2;
	Sprite transition;
	Player player;
	Demon demon;

	RectangleShape transBack;

	int lastTurn;
	int opacity;
	float transHeight;

	bool transeScene;

	void InitMap(std::string filepath, std::string level);
public:
	StageScene(SceneManager& sceneManager);

	virtual void Init();

	virtual void Update(Time& dt);

	virtual void Render();

	virtual void Release();

	void TranseScene(float dt);

	virtual ~StageScene();
};

