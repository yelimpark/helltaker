#pragma once
#include <list>
#include <iostream>

#include "./Scene.h"
#include "../UI/StageUI.h"
#include "../SceneInitializer/StageSceneInitializer.h"
#include <list>
#include <iostream>
#include "../GameObj/Box.h"
#include "PauseMenu.h"

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
	std::vector<boxInfo> boxdatas;
	
	std::list<FlameBase *> flameBases;
	Sprite spriteBackground;
	Sprite spriteSide1;
	Sprite spriteSide2;
	Sprite transition;

	PauseMenu *pmenu;

	RectangleShape transBack;


	int lastTurn;
	int opacity;
	float transHeight;
	
	std::vector<Box*> boxes;

	bool pause; //for esc menu 
	bool transeScene;

public:
	StageScene(SceneManager& sceneManager);
	virtual void Init();

	void UpdatePauseInput(Time& dt);
	virtual void Update(Time& dt);
	virtual void Render();
	virtual void InitPauseMenu();

	virtual void PauseState();
	virtual void UnPauseState();
	virtual void Release();
	void TranseScene(float dt);
	virtual ~StageScene();
};

