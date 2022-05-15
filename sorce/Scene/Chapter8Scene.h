#pragma once
#include <SFML/Graphics.hpp>
#include "./Scene.h"
#include "../GameObj/Player.h"
#include "../UI/StageUI.h"
#include "./PauseMenu.h"
#include <vector>

using namespace sf;

class Chapter8Scene : public Scene
{
private:
	const int TILE_SIZE = 100;
	const float MOVE_SECOND = 0.1f;

	Sprite background;
	Player player;
	std::vector<Skull*> skulls;

	StageUI ui;
	PauseMenu pmenu;

	bool paused;
	bool isClear;

	View& playerView;

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

