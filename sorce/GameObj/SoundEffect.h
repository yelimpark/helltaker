#pragma once
#include "../Resource/SoundHolder.h"
#include "../Utils/Singleton.h"

class SoundEffect : public Singleton<SoundEffect>
{
private:
	Music stageMusic;
	Music openMusic;

	Music* curbgm;

public:
	static void SoundEffectPlay(std::string soundName);

	static void changebgm();

	static void menuConfirm();
	static void menuHighlight();
	static void dialogueTextEnd();
	static void cutTransition1();
	static void cutTransition2();

	static void Playermoves();
	static void PlayerInClaw();
	static void kickSkull();
	static void kickBox();
	static void moveBox();
	static void crushSkull();
	static void getKey();

	static void dialogueStart();
	static void dialogueSuccess();
	static void dialogueConfirm();

	static void turnOver();
	static void badEnding();
	static void catchDemon();

	void backgroundMusic();
	void openingMusic();
};

