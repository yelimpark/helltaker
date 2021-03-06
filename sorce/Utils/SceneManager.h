#pragma once
#include "./GameVal.h"
#include "./Singleton.h"
#include "../GameObj/CutSceneTransition.h"
#include "../GameObj/SoundEffect.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Scene;

enum class SceneType {
	INITLOADING,
	TITLE,
	STAGE,
	CUT,
	STAGE8,
	BADENDING,
	COUNT
};

class SceneManager : public Singleton<SceneManager>
{
private:
	SceneType currScene;
	SceneType holdScene;
	Scene* scenes[(int)SceneType::COUNT];

	GameVal gameVal;
	
	CutSceneTransition transition;
	bool transitionActive;

	SoundEffect soundEffects;

public:
	void Init();

	void Release();

	void Update(Time& dt);

	void Render();

	void ChangeScene(SceneType newScene, bool transitionActive = false);

	virtual ~SceneManager();
};