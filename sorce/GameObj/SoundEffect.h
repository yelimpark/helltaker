#pragma once
#include "../Resource/SoundHolder.h"

class SoundEffect
{
private:
	Music music;

public:
	void menuConfirm();
	void menuHighlight();
	void dialogueTextEnd();
	void cutTransition1();
	void cutTransition2();

	void Playermoves();
	void PlayerInClaw();
	void kickSkull();
	void kickBox();
	void moveBox();
	void crushSkull();
	void getKey();

	void dialogueStart();
	void dialogueSuccess();
	void dialogueConfirm();

	void badEnding();
	void catchDemon();

	void backgroundMusic();
	void openingMusic();
};

