#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "../Resource/AnimationController.h"
#include "../SceneInitializer/LevelEndingSceneInitializer.h"

using namespace sf;

enum class UpdateOutput {
	HOLD,
	SKIP,
	BADEND
};

class Script {
protected:
	Sprite character;
	Text name;
	Text line;

public:
	Script();

	virtual UpdateOutput Update(float dt) = 0;

	virtual void Draw(RenderWindow& window) = 0;
};