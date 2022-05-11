#pragma once
#include "./Script.h"
#include "../Resource/AnimationController.h"

class ScriptWithAnimation : public Script {
private:
	Sprite sprite;
	AnimationController animation;

public:
	ScriptWithAnimation();

	void Init(LevelEndngData& data, Vector2i resolution);

	virtual UpdateOutput Update(float dt);

	virtual void Draw(RenderWindow& window);

	virtual void Release();

	virtual ~ScriptWithAnimation();
};