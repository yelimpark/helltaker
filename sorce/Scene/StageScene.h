#pragma once
#include "./Scene.h"
#include "../UI/StageUI.h"
#include "../SceneInitializer/StageSceneInitializer.h"
#include "../GameObj/Player.h"
#include "../GameObj/Demon.h"
#include "../GameObj/BoneParticle.h"
#include "../GameObj/stageSceneTrasition.h"
#include "../GameObj/CutSceneTransition.h"
#include "../GameObj/GameOver.h"
#include "../GameObj/SoundEffect.h"
#include "../GameObj/Claw.h"
#include <vector>

class Flame;
class Box;
class Skull;

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
	std::vector<Skull *> skulls;
	
	StageUI ui;

	Sprite Background;
	Sprite sideLeft;
	Sprite sideRight;
	Player player;
	Demon demon;
	Claw claw;

	BoneParticle boneParticle;
	stageSceneTrasition stageTransition;
	CutSceneTransition cutTransition;

	GameOver gameOver;
	SoundEffect soundEffects;

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