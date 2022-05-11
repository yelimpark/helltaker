#pragma once
#include "./Scene.h"
#include <SFML/Graphics.hpp>
#include "../Resource/AnimationController.h"
#include <vector>

using namespace sf;

class BadEndingScene : public Scene {
private:
	Sprite sprite;
	AnimationController animation;
	std::vector<Text *> texts;

public:
	BadEndingScene(SceneManager& sceneManager);

	virtual void Init();

	virtual void Update(Time& dt);

	virtual void Render();

	virtual void Release();

	virtual ~BadEndingScene();
};