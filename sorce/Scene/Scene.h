#pragma once
#include "../Utils/SceneManager.h"

class Scene {
protected:
	SceneManager& sceneManager;
	const Vector2i& resolution;
	RenderWindow& window;
	const View& mainView;

public:
	Scene(SceneManager& sceneManager);

	virtual void Init() = 0;

	virtual void Update(Time& dt) = 0;

	virtual void Render() = 0;

	virtual void Release() = 0;

	virtual ~Scene();
};