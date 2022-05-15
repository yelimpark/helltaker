#pragma once
#include <SFML/Graphics.hpp>
#include "../Resource/AnimationController.h"
#include "./SoundEffect.h"

using namespace sf;

class BoneParticle
{
private:
	Sprite sprite;
	AnimationController animation;

	SoundEffect soundEffects;
public:
	BoneParticle();

	void Init(Vector2f pos);

	void Update(float dt);

	void Draw(RenderWindow& window);

	~BoneParticle();
};

