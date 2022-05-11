#include "ScriptWithAnimation.h"
#include "../Resource/ResorceHolder.h"
#include "../Utils/Utils.h"
#include "../Utils/InputManager.h"

ScriptWithAnimation::ScriptWithAnimation()
	:Script()
{
}

void ScriptWithAnimation::Init(LevelEndngData& data, Vector2i resolution)
{
	character.setTexture(TextureHolder::GetTexture(data.characterFileName));
	//Utils::SetOrigin(character, Pivots::CenterBottom);
	
	name.setFont(FontHolder::GetFont("Font/CrimsonPro-Medium.ttf"));
	name.setString(data.name);
	name.setCharacterSize(40);
	name.setFillColor(Color{ 230,77,81 });
	name.setPosition(resolution.x * 0.5, 900.f);
	std::cout << data.name << std::endl;

	line.setFont(FontHolder::GetFont("Font/CrimsonPro-Medium.ttf"));
	line.setString(data.line);
	line.setCharacterSize(30);
	line.setFillColor(Color::White);
	
	animation.SetTarget(&sprite);
	animation.AddClip(data.animationClipName);
	animation.Play(data.animationClipName);
}

UpdateOutput ScriptWithAnimation::Update(float dt)
{
	animation.Update(dt);
	if (InputManager::GetKeyDown(Keyboard::Enter)) {
		return UpdateOutput::SKIP;
	}
	return UpdateOutput::HOLD;
}

void ScriptWithAnimation::Draw(RenderWindow& window)
{
	window.draw(character);
	window.draw(sprite);
	window.draw(line);
	window.draw(name);
}
