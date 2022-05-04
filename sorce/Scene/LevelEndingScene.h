#pragma once
#include "./Scene.h"
#include "../Resource/AnimationController.h"

#define MAX_NUMBER_OF_ITEMS 2
class LevelEndingScene : public Scene
{
private:
	Text textMain;
	Text textintro;
	Sprite hellbackground;
	Sprite img;

	std::string script[50];
	Texture *interimg;


	Vector2f position;
	
	Sprite bg;


	int textselectIndex;
	int textureselectIndex;
	int enterCount;


	const Vector2i& resolution;
	RenderWindow& window;
	View& mainView;

public:
	LevelEndingScene(SceneManager& sceneManager);

	virtual void Init();

	virtual void Update(Time& dt);

	virtual void Render();

	virtual void MoveUp();

	virtual void MoveDown();

	virtual int GetPressedMenu();

	virtual void Release();

	virtual ~LevelEndingScene();

};

