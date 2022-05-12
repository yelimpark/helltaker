#include "BadEndingScene.h"
#include "../Utils/Utils.h"
#include "../Utils/rapidcsv.h"
#include "../Resource/FontHolder.h"

#include <sstream>

BadEndingScene::BadEndingScene(SceneManager& sceneManager)
	: Scene(sceneManager)
{
}

void BadEndingScene::Init()
{
	Release();

	animation.SetTarget(&sprite);
	animation.AddClip("dialogueDeath");
	animation.Play("dialogueDeath");
	Utils::SetOrigin(sprite, Pivots::Center);
	sprite.setPosition(resolution.x * 0.5, resolution.y * 0.5);

	bgColor.setSize(Vector2f(resolution.x, resolution.y));
	bgColor.setFillColor(Color{ 2, 2, 27 });
	bgColor.setPosition(0, 0);

	std::stringstream ss;
	ss << GameVal::level;

	rapidcsv::Document csvData("./LevelInfo/BadEndInfo.csv", rapidcsv::LabelParams(0, 0));
	std::string line = csvData.GetCell<std::string>("line",ss.str());
	
	std::istringstream iss(line);
	float top = 900.f;
	int idx = 0;
	std::string token;
	while (getline(iss, token, '-')) {
		Text * text = new Text();
		text->setString(token);
		text->setFont(FontHolder::GetFont("Font/CrimsonPro-Medium.ttf"));
		text->setFillColor(Color{ 230,77,81 });
		Utils::SetOrigin(*text, Pivots::Center);
		text->setPosition(resolution.x * 0.5, top + 40.f * idx);
		texts.push_back(text);
		++idx;
	}
}

void BadEndingScene::Update(Time& dt)
{
	animation.Update(dt.asSeconds());
	Utils::SetOrigin(sprite, Pivots::Center);
}

void BadEndingScene::Render()
{
	window.draw(bgColor);
	window.draw(sprite);
	for (auto& text : texts) {
		window.draw(*text);
	}
}

void BadEndingScene::Release()
{
	for (auto& text : texts) {
		if (text != nullptr)
			delete text;
	}
	texts.clear();
}

BadEndingScene::~BadEndingScene()
{
	Release();
}
