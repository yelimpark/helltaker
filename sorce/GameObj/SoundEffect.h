#pragma once
#include "../Resource/SoundHolder.h"
#include "../Utils/Singleton.h"

class SoundEffect
{
private:
	Music stageMusic;
	Music openMusic;

	Music* curbgm;

public:
	static void SoundEffectPlay(std::string soundName);

	//static void changebgm(Music music);

	void backgroundMusic();
	void openingMusic();

	void makeMusicVolumeHigh();
	void makeMusicVolumeMedium();
	void makeMusicVolumeLow();
};

