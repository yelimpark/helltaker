#include "Chapter8Scene.h"
#include "../Framework/Framework.h"
#include "../Utils/InputManager.h"
#include "../Resource/TextureHolder.h"
#include "../Utils/Utils.h"

Chapter8Scene::Chapter8Scene(SceneManager& sceneManager)
	:Scene(sceneManager),
	playerView(Framework::GetPlayerView()), pmenu(window, sceneManager), isClear(false)
{
}

void Chapter8Scene::Init()
{
	background.setTexture(TextureHolder::GetTexture("Sprite/chapterSketches_EXPORT_throne.png"));
	player.Init(Vector2f(resolution.x*0.5f, resolution.y*1.5f), TILE_SIZE, MOVE_SECOND);

	paused = false;
	isClear = false;
}

void Chapter8Scene::Update(Time& dt)
{
	UpdatePauseInput(dt);
	if (paused) {
		pmenu.Update();
		return;
	}

	player.Update(dt.asSeconds());


}

void Chapter8Scene::PausedState()
{
	paused = true;
	pmenu.UpInit();
}

void Chapter8Scene::UnPausedState()
{
	paused = false;
}

void Chapter8Scene::UpdatePauseInput(Time& dt)
{
	if (InputManager::GetKeyDown(Keyboard::Escape))
	{
		if (!paused)
		{
			PausedState();
		}
		else
		{
			UnPausedState();
		}
	}
}


void Chapter8Scene::Render()
{
	window.setView(playerView);
	window.draw(background);
	player.Draw(window);

	window.setView(mainView);
	
}

void Chapter8Scene::Release()
{
}

Chapter8Scene::~Chapter8Scene()
{
}
