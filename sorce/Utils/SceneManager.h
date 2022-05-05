#pragma once
#include "./GameVal.h"
#include "./Singleton.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Scene;

enum class SceneType {
	TITLE,
	STAGE,
	TITLESCRIPT,
	ENDINGCUTSCENE,
	COUNT
};

class SceneManager : public Singleton<SceneManager> 
{
private:
	SceneType currScene;
	Scene* scenes[(int)SceneType::COUNT];

	GameVal gameVal;

public:
	void Init();

	void Release();

	void Update(Time& dt);

	void Render();

	void ChangeScene(SceneType newScene);

	virtual ~SceneManager();
};