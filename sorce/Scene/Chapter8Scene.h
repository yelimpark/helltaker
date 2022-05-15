#pragma once
#include <SFML/Graphics.hpp>
#include "./Scene.h"
#include "../SceneInitializer/StageSceneInitializer.h"
#include "../UI/StageUI.h"
#include "./PauseMenu.h"
#include "../GameObj/Player.h"
#include "../GameObj/BoneParticle.h"
#include "../GameObj/stageSceneTrasition.h"
#include "../GameObj/GameOver.h"
#include <vector>
#include <list>

using namespace sf;

class Flame;
class Box;
class Skull;
class Demon;
class LockedBox;

class Chapter8Scene : public Scene
{
private:
	char** map;

	const int TILE_SIZE = 100;
	const float MOVE_SECOND = 0.1f;

	Sprite background;
	Sprite sideLeft;
	Sprite sideRight;

	Player player;


	std::vector<Skull*> skulls;
	std::vector<Flame*> flames;
	std::vector<Sprite*> flameBases;
	std::vector<Box*> boxes;
	LockedBox* lockedBox;

	BoneParticle boneParticle;

	StageUI ui;
	PauseMenu pmenu;

	bool paused;
	bool isClear;

	stageSceneTrasition stageTransition;
	GameOver gameOver;

	View& playerView;

	void InitMap(std::string filepath);

public:
	Chapter8Scene(SceneManager& sceneManager);
	virtual void Init();
	virtual void Update(Time& dt);
	virtual void PausedState();
	virtual void UnPausedState();
	virtual void UpdatePauseInput(Time& dt);

	virtual void Render();
	virtual void Release();
	virtual ~Chapter8Scene();
};

