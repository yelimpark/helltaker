#include "InitLoadingScene.h"
#include "../Resource/TextureHolder.h"
#include "../Resource/AnimationHolder.h"
#include "../Utils/Utils.h"

InitLoadingScene::InitLoadingScene(SceneManager& sceneManager)
	: Scene(sceneManager), firstRender(false)
{
}

void InitLoadingScene::Init()
{
	sprite.setTexture(TextureHolder::GetTexture("Sprite/initLoading.jpg"));
	Utils::SetOrigin(sprite, Pivots::Center);
	sprite.setPosition(resolution.x * 0.5, resolution.y * 0.5);

	bgColor.setSize(Vector2f(resolution.x, resolution.y));
	bgColor.setFillColor(Color{ 0, 0, 3 });
	bgColor.setPosition(0, 0);
}

void InitLoadingScene::Update(Time& dt)
{
	if (!firstRender) return;
	AnimationHolder::GetAnimation("GameOver");
	AnimationHolder::GetAnimation("CutTransition");
	AnimationHolder::GetAnimation("dialogueDeath");
	AnimationHolder::GetAnimation("success_all");
	sceneManager.ChangeScene(SceneType::TITLE);
}

void InitLoadingScene::Render()
{
	window.draw(bgColor);
	window.draw(sprite);
	firstRender = true;
}

void InitLoadingScene::Release()
{
}

InitLoadingScene::~InitLoadingScene()
{
}
