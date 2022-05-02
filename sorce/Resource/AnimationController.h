#pragma once
#include "AnimationClip.h"
#include <map>
#include <queue> //먼저들어간놈이 먼저나오는 자료구조

using namespace sf;

class AnimationController
{
private:
	std::map<std::string, AnimationClip> clips; //animation clip을 id(string)으로 찾게하기 위해
	std::queue<std::string> playQueue;

	AnimationClip* currenetClip; // 포인터형으로 현재 클립 갖고있겠다
	bool isPlaying; //재생중인지 아닌지 확인
	int currentFrame;
	int totalFrame;
	float frameDuration;

	float sspeed;

	float accumTime;

	Sprite* sprite;


public:

	AnimationController(); //기본 생성자

	void SetTarget(Sprite* sprite);

	void AddClip(const AnimationClip& newClip);

	void Update(float dt);

	void Play(std::string clipId, bool clear = true);
	void PlayQueue(std::string clipId);

	void CloarPlayQueue();
	void Stop();

	void GetSpeed(float sspeed);

	bool IsPlaying(); //밖에서 사용
};

