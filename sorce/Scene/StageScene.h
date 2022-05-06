#pragma once
#include "./Scene.h"
#include "../UI/StageUI.h"
#include "../SceneInitializer/StageSceneInitializer.h"
#include "../GameObj/Player.h"
#include "../GameObj/Demon.h"
#include "../GameObj/Box.h"

#include <vector>

class Flame;

class StageScene : public Scene
{
private:
	StageUI ui;

	int level;
	char ** map;

	const int TILE_SIZE = 100; 

	std::vector<boxInfo> boxdatas;
	
	std::vector<Flame *> flames;
	std::vector<Sprite *> flameBases;

	Sprite spriteBackground;
	Sprite spriteSide1;
	Sprite spriteSide2;
	Sprite transition;
	Player player;
	Demon demon;

	RectangleShape transBack;

	int lastTurn;
	int opacity;
	float transHeight;
	
	std::vector<Box*> boxes;

	bool transeScene;

	void InitMap(std::string filepath);
public:
	StageScene(SceneManager& sceneManager);

	virtual void Init();

	virtual void Update(Time& dt);

	virtual void Render();

	virtual void Release();

	void TranseScene(float dt);

	virtual ~StageScene();
};

