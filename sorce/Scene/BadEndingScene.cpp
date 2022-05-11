#include "BadEndingScene.h"
#include "../Utils/Utils.h"

#include <sstream>

BadEndingScene::BadEndingScene(SceneManager& sceneManager)
	: Scene(sceneManager)
{
}

void BadEndingScene::Init()
{
	animation.SetTarget(&sprite);
	animation.AddClip("dialogueDeathExport0002_s");
	animation.Play("dialogueDeathExport0002_s");
	Utils::SetOrigin(sprite, Pivots::Center);
	sprite.setPosition(resolution.x * 0.5, resolution.y * 0.5);

	std::stringstream ss;
	ss << GameVal::level;
}

void BadEndingScene::Update(Time& dt)
{
	animation.Update(dt.asSeconds());
	Utils::SetOrigin(sprite, Pivots::Center);
}

void BadEndingScene::Render()
{
	window.draw(sprite);
}

void BadEndingScene::Release()
{
}

BadEndingScene::~BadEndingScene()
{
}
