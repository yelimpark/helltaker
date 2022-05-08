#pragma once
#include "../Resource/SoundHolder.h"

class SoundEffect
{
private:
	Sound sound;

public:
	void menuConfirm();
	void menuHighlight();
	void dialogueTextEnd();
	void screenTransition();
	void kickSkull();
	void kickBox();
	void dialogueStart();
	void dialogueSuccess();
	void dialogueConfirm();
	void badEnding();
	void catchDemon();
};

