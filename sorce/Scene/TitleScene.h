#pragma once
#include "./Scene.h"

class TitleScene : public Scene 
{
private:
	

public:
	TitleScene(SceneManager& sceneManager);

	virtual void Init();

	virtual void Update(Time& dt);

	virtual void Render();

	virtual void Release();

	virtual ~TitleScene();
};