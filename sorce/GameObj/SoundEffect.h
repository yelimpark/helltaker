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
	void screenTransition();

	void Playermoves();
	void kickSkull();
	void kickBox();
	void moveBox();
	void crushSkull();

	void dialogueStart();
	void dialogueSuccess();
	void dialogueConfirm();

	void badEnding();
	void catchDemon();

	void backgroundMusic();
	void openingMusic();
};

