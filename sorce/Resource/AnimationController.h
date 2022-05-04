#pragma once
#include "AnimationClip.h"
#include <list>

using namespace sf;

class AnimationController {
private:
	std::map<std::string, AnimationClip> clips;
	bool isPlaying;
	int currentFrame;
	int totalFrame;
	float frameDuration;

	float accumTime;

	Sprite* sprite;

	AnimationClip* currentClip;

	std::list<std::string> que;

public:
	AnimationController();

	void SetTarget(Sprite* sprite);

	void AddClip(std::string);

	void Update(float dt);

	void PlayQue(std::string clipId);

	void Play(std::string clipId, bool clear = true);

	void stop();

	bool IsPlaying();

	void changePlayTime(float time);

	bool IsAnimationEnd();

};