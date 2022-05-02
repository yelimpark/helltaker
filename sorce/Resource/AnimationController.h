#pragma once
#include "AnimationClip.h"
#include <map>
#include <queue> //���������� ���������� �ڷᱸ��

using namespace sf;

class AnimationController
{
private:
	std::map<std::string, AnimationClip> clips; //animation clip�� id(string)���� ã���ϱ� ����
	std::queue<std::string> playQueue;

	AnimationClip* currenetClip; // ������������ ���� Ŭ�� �����ְڴ�
	bool isPlaying; //��������� �ƴ��� Ȯ��
	int currentFrame;
	int totalFrame;
	float frameDuration;

	float sspeed;

	float accumTime;

	Sprite* sprite;


public:

	AnimationController(); //�⺻ ������

	void SetTarget(Sprite* sprite);

	void AddClip(const AnimationClip& newClip);

	void Update(float dt);

	void Play(std::string clipId, bool clear = true);
	void PlayQueue(std::string clipId);

	void CloarPlayQueue();
	void Stop();

	void GetSpeed(float sspeed);

	bool IsPlaying(); //�ۿ��� ���
};

