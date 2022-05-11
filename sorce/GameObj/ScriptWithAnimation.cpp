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
	Release();

	character.setTexture(TextureHolder::GetTexture(data.characterFileName));
	//Utils::SetOrigin(character, Pivots::CenterBottom);
	
	name.setFont(FontHolder::GetFont("Font/CrimsonPro-Medium.ttf"));
	name.setString(data.name);
	name.setCharacterSize(40);
	name.setFillColor(Color{ 230,77,81 });
	name.setPosition(resolution.x * 0.5, 900.f);
	std::cout << data.name << std::endl;

	std::istringstream iss(data.line);
	float top = 800.f;
	int idx = 0;
	std::string token;
	while (getline(iss, token, '-')) {
		Text* text = new Text();
		text->setString(token);
		text->setFont(FontHolder::GetFont("Font/CrimsonPro-Medium.ttf"));
		text->setFillColor(Color::White);
		Utils::SetOrigin(*text, Pivots::Center);
		text->setPosition(resolution.x * 0.5, top + 40.f * idx);
		texts.push_back(text);
		++idx;
	}
	
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
	for (auto& text : texts) {
		window.draw(*text);
	}
	window.draw(name);
}

void ScriptWithAnimation::Release()
{
	for (auto& text : texts) {
		if (text != nullptr)
			delete text;
	}
	texts.clear();
}

ScriptWithAnimation::~ScriptWithAnimation()
{
	Release();
}
