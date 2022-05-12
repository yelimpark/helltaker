#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "../Resource/AnimationController.h"
#include "../SceneInitializer/LevelEndingSceneInitializer.h"
#include <vector>

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
	std::vector<Text*> texts;

	void Init(LevelEndngData& data, Vector2i resolution);

public:
	Script();

	virtual UpdateOutput Update(float dt) = 0;

	virtual void Draw(RenderWindow& window);

	virtual void Release();

	virtual ~Script();
};