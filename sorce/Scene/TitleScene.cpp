#include "TitleScene.h"
#include "../Utils/Utils.h"
#include "../Resource/TextureHolder.h"
#include "../Utils/InputManager.h"

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

	leng.setTexture(TextureHolder::GetTexture("Sprite/EN_Icon.png"));
	leng.setScale(0.2f, 0.2f);
	Utils::SetOrigin(leng, Pivots::RightBottom);
	leng.setPosition(resolution.x - 50.f, resolution.y - 50.f);
	leng.setColor(Color::White);

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

	if (InputManager::GetKeyDown(Keyboard::L)) {
		if (GameVal::language.compare("Es") == 0) {
			leng.setTexture(TextureHolder::GetTexture("Sprite/EN_Icon.png"));
			GameVal::language = "";
		}
		else {
			leng.setTexture(TextureHolder::GetTexture("Sprite/ES_Icon.png"));
			GameVal::language = "Es";
		}
	}
}

void TitleScene::Render()
{
	window.draw(bg);
	window.draw(chara);
	window.draw(leng);
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
