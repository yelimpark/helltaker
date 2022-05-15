#pragma once
#include "./Scene.h"
#include <SFML/Graphics.hpp>
#include "../GameObj/MainMenu.h"
#include "../GameObj/ChapterMenu.h"

using namespace sf;

class TitleScene : public Scene
{
private:
	Sprite bg;
	Sprite chara;

	Sprite leng;

	MainMenu mainM;
	ChapterMenu chapM;
	bool IsChapMActive;

public:
	TitleScene(SceneManager& sceneManager);

	virtual void Init();

	virtual void Update(Time& dt);

	virtual void Render();

	virtual void Release();

	virtual ~TitleScene();
};