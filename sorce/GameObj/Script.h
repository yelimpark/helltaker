#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "../Resource/AnimationController.h"
#include "../SceneInitializer/CutSceneInitializer.h"
#include <vector>

using namespace sf;

class Script {
protected:
	Sprite character;
	Text name;
	std::vector<Text*> texts;
	Sprite background;
	std::string nextNode;

	void Init(CutSceneData& data, Vector2i resolution);

public:
	Script();

	virtual bool Update(float dt) = 0;

	virtual void Draw(RenderWindow& window);

	virtual void Release();

	virtual ~Script();

	std::string& GetNextNode();
};