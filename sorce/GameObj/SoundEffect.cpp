#include "SoundEffect.h"
#include <iostream>

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

void SoundEffect::cutTransition1()
{
	(SoundHolder::GetSound("Sound/screen_changer_part1_01.wav")).play();
}

void SoundEffect::cutTransition2()
{
	(SoundHolder::GetSound("Sound/screen_changer_part2_01.wav")).play();
}

void SoundEffect::Playermoves()
{
	(SoundHolder::GetSound("Sound/character_move_01.wav")).play();
}

void SoundEffect::PlayerInClaw()
{
	(SoundHolder::GetSound("Sound/spikes_damage_01.wav")).play();
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

void SoundEffect::getKey()
{
	(SoundHolder::GetSound("Sound/key_pick_up_01.wav")).play();
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

void SoundEffect::openingMusic()
{
	openMusic.openFromFile("Sound/Apropos.wav");
	openMusic.play();
}


void SoundEffect::backgroundMusic()
{
	stageMusic.openFromFile("Sound/Vitality.wav");
	stageMusic.setLoop(true);
	stageMusic.play();
}
