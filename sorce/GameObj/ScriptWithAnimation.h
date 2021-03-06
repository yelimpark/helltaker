#pragma once
#include "./Script.h"
#include "../Resource/AnimationController.h"
#include "./SoundEffect.h"

class ScriptWithAnimation : public Script {
private:
	Sprite sprite;
	AnimationController animation;

	SoundEffect soundEffects;

public:
	ScriptWithAnimation();

	void Init(CutSceneData& data, Vector2i resolution);

	virtual bool Update(float dt);

	virtual void Draw(RenderWindow& window);

	virtual ~ScriptWithAnimation();
};