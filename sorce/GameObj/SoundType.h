#pragma once
#include <SFML/Graphics.hpp>
#include "./SoundEffect.h"

using namespace sf;

#define MAX_NUMBER_OF_SOUND 3
enum class VolumeType
{
	HIGH,
	MEDIUM,
	LOW,
	COUNT,
};

class SoundType
{
private:

	RectangleShape container;

	int musicSound;
	int effectSound;

	Text musicSound_t;
	Text effectSound_t;

	String musicSound_s[MAX_NUMBER_OF_SOUND];
	String effectSound_s[MAX_NUMBER_OF_SOUND];

	int sideselectIndex;

	SoundEffect soundEffects;
	VolumeType type;

public:

	SoundType(VolumeType type);

	virtual void SideInit();

	virtual void MusicInputButton();

	virtual void EffectInputButton();

	virtual void MoveRight();

	virtual void MoveLeft();

	void Update(VolumeType type);

	virtual void Render(RenderWindow& window);

};