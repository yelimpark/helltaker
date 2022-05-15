#pragma once
#include "./Scene.h"
#include "../UI/StageUI.h"
#include "../SceneInitializer/StageSceneInitializer.h"
#include "../GameObj/Player.h"
#include "../GameObj/BoneParticle.h"
#include "../GameObj/stageSceneTrasition.h"
#include "../GameObj/GameOver.h"
#include "../GameObj/BloodVfx.h"
#include "PauseMenu.h"
#include <vector>

class Flame;
class Box;
class Skull;
class Claw;
class Demon;
class Key;
class LockedBox;

class StageScene : public Scene
{
private:
	char ** map;

	const int TILE_SIZE = 100; 
	const float MOVE_SECOND = 0.1f;

	std::vector<Flame *> flames;
	std::vector<Sprite *> flameBases;
	std::vector<Box *> boxes;
	std::vector<Skull *> skulls;
	std::vector<Claw *> claws;
	std::vector<Demon *> demons;
	Key* key;
	LockedBox* lockedBox;

	Player player;
	
	StageUI ui;

	Sprite Background;
	Sprite sideLeft;
	Sprite sideRight;

	BoneParticle boneParticle;
	BloodVfx bloodVfx;
	stageSceneTrasition stageTransition;
	GameOver gameOver;

	SoundEffect soundEffects;

	PauseMenu pmenu;
	bool paused;

	bool isClear;

	void InitMap(std::string filepath, std::string clawFilePath, std::string demonName);

public:
	StageScene(SceneManager& sceneManager);

	virtual void Init();

	virtual void PausedState();

	virtual void UnPausedState();

	virtual void UpdatePauseInput(Time& dt);

	virtual void Update(Time& dt);

	virtual void Render();

	virtual void Release();

	virtual ~StageScene();

	int GetTileSize();
};