#pragma once
#include <list>
#include <iostream>

#include "./Scene.h"
#include "../UI/StageUI.h"
#include "../SceneInitializer/StageSceneInitializer.h"
#include <list>
#include <iostream>
#include "../GameObj/Box.h"

struct boxInfo
{
	std::string textureFilename;
	Vector2f position;
};


class FlameBase;

class StageScene : public Scene
{
private:
	StageUI ui;

	int level;
	std::map<std::string, LevelData> levelDatas;
	std::map<std::string, std::vector<FlameBaseData>> flameBaseDatas;
	
	std::list<FlameBase *> flameBases;
	Sprite spriteBackground;
	Sprite spriteSide1;
	Sprite spriteSide2;
	Sprite transition;

	RectangleShape transBack;

	int lastTurn;
	int opacity;
	float transHeight;
	
	std::vector<Box*> boxes;


	bool transeScene;

public:
	StageScene(SceneManager& sceneManager);
	virtual void Init();
	virtual void Update(Time& dt);
	virtual void Render();
	virtual void Release();
	void TranseScene(float dt);
	virtual ~StageScene();
};

