#pragma once
#include "./Scene.h"
#include <SFML/Graphics.hpp>

class InitLoadingScene : public Scene {
private:
	Sprite sprite;
	RectangleShape bgColor;

	bool firstRender;

public:
	InitLoadingScene(SceneManager& sceneManager);

	virtual void Init();

	virtual void Update(Time& dt);

	virtual void Render();

	virtual void Release();

	virtual ~InitLoadingScene();
};