#include "SoundEffect.h"
#include <iostream>

void SoundEffect::SoundEffectPlay(std::string soundName)
{
	(SoundHolder::GetSound(soundName)).play();
}

//void SoundEffect::changebgm(Music music)
//{
//	if (music == *curbgm) { // ���ݺ�������������������������ٸ�
//		return;
//	}
//	curbgm = music;
//}

void SoundEffect::openingMusic()
{
	openMusic.openFromFile("Sound/Apropos.wav");
	openMusic.play();
}

void SoundEffect::makeMusicVolumeHigh()
{
	stageMusic.setVolume(100);
}

void SoundEffect::makeMusicVolumeMedium()
{
	stageMusic.setVolume(50);
}

void SoundEffect::makeMusicVolumeLow()
{
	stageMusic.setVolume(20);
}


void SoundEffect::backgroundMusic()
{
	stageMusic.openFromFile("Sound/Vitality.wav");
	stageMusic.setLoop(true);
	stageMusic.play();
	stageMusic.setVolume(100);
}
