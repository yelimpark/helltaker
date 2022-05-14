#include "ScriptWithAnimation.h"
#include "../Resource/ResorceHolder.h"
#include "../Utils/Utils.h"
#include "../Utils/InputManager.h"

ScriptWithAnimation::ScriptWithAnimation()
{
}

void ScriptWithAnimation::Init(LevelEndngData& data, Vector2i resolution)
{
	Script::Init(data, resolution);

	sprite.setPosition(resolution.x * 0.5, 940);
	Utils::SetOrigin(sprite, Pivots::Center);

	animation.SetTarget(&sprite);
	animation.AddClip(data.animationClipName);
	animation.Play(data.animationClipName);
}

UpdateOutput ScriptWithAnimation::Update(float dt)
{
	animation.Update(dt);
	Utils::SetOrigin(sprite, Pivots::Center);

	if (InputManager::GetKeyDown(Keyboard::Enter)) {
		return UpdateOutput::SKIP;
	}
	return UpdateOutput::HOLD;
}

void ScriptWithAnimation::Draw(RenderWindow& window)
{
	window.draw(sprite);
	Script::Draw(window);
}

ScriptWithAnimation::~ScriptWithAnimation()
{
}
