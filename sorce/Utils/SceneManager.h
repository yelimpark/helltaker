#pragma once
#include "./GameVal.h"
#include "./Singleton.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Scene;

enum class SceneType {
	TITLE,
	TITLESCRIPT,
	STAGE,
	LEVELENDING,
	BADENDING,
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

	void Start();

	void Update(Time& dt);

	void Render();

	void ChangeScene(SceneType newScene);

	virtual ~SceneManager();
};