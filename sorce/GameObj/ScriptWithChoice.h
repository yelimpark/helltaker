#pragma once
#include "./Script.h"
#include <SFML/Graphics.hpp>
#include "./Option.h"
#include "./SoundEffect.h"

using namespace sf;

class ScriptWithChoice : public Script {
private:
	Option option[2];
	SoundEffect soundEffects;

public:
	ScriptWithChoice();

	void Init(CutSceneData& data, Vector2i resolution, OptionData& option1Data, OptionData& option2Data);

	virtual bool Update(float dt);

	virtual void Draw(RenderWindow& window);

	virtual ~ScriptWithChoice();
};