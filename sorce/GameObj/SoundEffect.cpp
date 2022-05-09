#include "SoundEffect.h"

void SoundEffect::menuConfirm()
{
	(SoundHolder::GetSound("Sound/button_menu_confirm_01.wav")).play();
}

void SoundEffect::menuHighlight()
{
	(SoundHolder::GetSound("Sound/button_menu_highlight_01.wav")).play();
}

void SoundEffect::dialogueTextEnd()
{
	(SoundHolder::GetSound("Sound/dialogue_text_end_01.wav")).play();
}

void SoundEffect::screenTransition()
{
	(SoundHolder::GetSound("Sound/screen_changer_part1_01.wav")).play();
	//(SoundHolder::GetSound("Sound/screen_changer_part2_01.wav")).play(); 몇 초 뒤 재생?
}

void SoundEffect::Playermoves()
{
	(SoundHolder::GetSound("Sound/character_move_01.wav")).play();
}

void SoundEffect::kickSkull()
{
	(SoundHolder::GetSound("Sound/enemy_kick_01.wav")).play();
}

void SoundEffect::kickBox()
{
	(SoundHolder::GetSound("Sound/stone_kick_01.wav")).play();
}

void SoundEffect::moveBox()
{
	(SoundHolder::GetSound("Sound/stone_move_02.wav")).play();
}

void SoundEffect::crushSkull()
{
	(SoundHolder::GetSound("Sound/enemy_die_01.wav")).play();
}

void SoundEffect::dialogueStart()
{
	(SoundHolder::GetSound("Sound/dialogue_start_01.wav")).play();
}

void SoundEffect::dialogueSuccess()
{
	(SoundHolder::GetSound("Sound/dialogue_success_01.wav")).play();
}

void SoundEffect::dialogueConfirm()
{
	(SoundHolder::GetSound("Sound/button_dialogue_confirm_01.wav")).play();
}

void SoundEffect::badEnding()
{
	(SoundHolder::GetSound("Sound/bad_end_screen_01.wav")).play();
}

void SoundEffect::catchDemon()
{
	(SoundHolder::GetSound("Sound/succub_capture_01.wav")).play();
}

void SoundEffect::backgroundMusic()
{
	Sound sound;
	sound = (SoundHolder::GetSound("Sound/Vitality.wav"));
	sound.play();
	sound.setLoop(true);
}

void SoundEffect::openingMusic()
{
	Sound sound;
	sound = (SoundHolder::GetSound("Sound/Apropos.wav"));
	sound.play();
}
