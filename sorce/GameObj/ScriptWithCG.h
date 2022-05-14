#pragma once
#include "ScriptWithAnimation.h"

class ScriptWithCG : public ScriptWithAnimation {
private:
	RectangleShape redRect;
	Sprite cg;

	const float EFFECT_TIME_MAX = 0.2f;
	float effectTime;

public:
	ScriptWithCG();

	void Init(CutSceneData& data, Vector2i resolution);

	virtual bool Update(float dt);

	virtual void Draw(RenderWindow& window);

	virtual ~ScriptWithCG();
};