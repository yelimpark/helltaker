#include "InitLoadingScene.h"
#include "../Resource/ResorceHolder.h"
#include "../Resource/AnimationHolder.h"
#include "../Utils/Utils.h"

InitLoadingScene::InitLoadingScene(SceneManager& sceneManager)
	: Scene(sceneManager), firstRender(false)
{
}

void InitLoadingScene::Init()
{
	sprite.setTexture(TextureHolder::GetTexture("Sprite/initLoading.png"));
	Utils::SetOrigin(sprite, Pivots::Center);
	sprite.setPosition(resolution.x * 0.5, resolution.y * 0.5);

	bgColor.setSize(Vector2f(resolution.x, resolution.y));
	bgColor.setFillColor(Color{ 0, 0, 3 });
	bgColor.setPosition(0, 0);

	text.setFont(FontHolder::GetFont("Font/CrimsonPro-Medium.ttf"));
	text.setString("Made by SFML");
	text.setCharacterSize(50);
	text.setFillColor(Color::White);
	Utils::SetOrigin(text, Pivots::Center);
	text.setPosition(resolution.x * 0.5, resolution.y * 0.5);
}

void InitLoadingScene::Update(Time& dt)
{
	if (!firstRender) return;
	AnimationHolder::GetAnimation("GameOver");
	AnimationHolder::GetAnimation("CutTransition");
	AnimationHolder::GetAnimation("dialogueDeath");
	AnimationHolder::GetAnimation("success_all");

	GameVal::cutSceneIdx = -1;
	sceneManager.ChangeScene(SceneType::CUT);
}

void InitLoadingScene::Render()
{
	window.draw(bgColor);
	window.draw(sprite);
	window.draw(text);
	firstRender = true;
}

void InitLoadingScene::Release()
{
}

InitLoadingScene::~InitLoadingScene()
{
}
