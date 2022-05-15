#include "TitleScene.h"
#include "../Utils/Utils.h"
#include "../Resource/TextureHolder.h"

TitleScene::TitleScene(SceneManager& sceneManager)
	:Scene(sceneManager), IsChapMActive(false)
{
}

void TitleScene::Init()
{
	IsChapMActive = false;

	bg.setTexture(TextureHolder::GetTexture("Sprite/dialogueBG_abyss_s.png"));
	Utils::SetOrigin(bg, Pivots::CenterBottom);
	bg.setPosition(resolution.x * 0.5, 700);

	chara.setTexture(TextureHolder::GetTexture("Sprite/beel_fly.png"));
	Utils::SetOrigin(chara, Pivots::CenterBottom);
	chara.setPosition(resolution.x * 0.5, 700);

	mainM.Init(resolution);
	chapM.Init(resolution);
}

void TitleScene::Update(Time& dt)
{
	if (IsChapMActive) {
		chapM.HandleInput(sceneManager);
	}
	else {
		if (mainM.HandleInput(window, sceneManager)) IsChapMActive = true;
	}
}

void TitleScene::Render()
{
	window.draw(bg);
	window.draw(chara);
	if (IsChapMActive) {
		chapM.Draw(window);
	}
	else {
		mainM.Draw(window);
	}
}

void TitleScene::Release()
{
	chapM.Release();
}

TitleScene::~TitleScene()
{
}
