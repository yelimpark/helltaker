#include "AnimationController.h"

AnimationController::AnimationController()
	:clips(), currenetClip(nullptr), isPlaying(false), currentFrame(-1), totalFrame(0), frameDuration(0.f), sprite(nullptr), sspeed(1.f)
{
}

void AnimationController::SetTarget(Sprite* sprite)
{
	this->sprite = sprite;
}

void AnimationController::AddClip(const AnimationClip& newClip)
{
	if (clips.find(newClip.id) == clips.end())
	{
		clips[newClip.id] = newClip;
	}
	else
	{

	}


}

void AnimationController::Update(float dt)
{
	if (!isPlaying) {
		return; //false�� ������Ʈ x
	}

	accumTime += dt * sspeed; //dt -> �������ð�

	if (accumTime < frameDuration)
	{
		return;
	} // ������ ��ü�� Ÿ���� �ƴ�

	accumTime = 0.f;
	++currentFrame;
	if (currentFrame >= totalFrame) //������ ������ ���ϰ��� ���������� ������
	{
		if (playQueue.empty()) //queue�� ����������� ����ó�� ���
		{
			switch (currenetClip->loopTypes)
			{
			case AnimationLoopTypes::Single:
				currentFrame = totalFrame - 1;
				break;
			case AnimationLoopTypes::Loop:
				currentFrame = 0;
				break;
			default:
				//error
				break;
			}
		}
		else//queue�� ��������������� ������ ������ ���� ������
		{
			// pop(���°�)
			std::string nextClip = playQueue.front();
			playQueue.pop();
			Play(nextClip, false);
		}
	}

	sprite->setTexture(currenetClip->frames[currentFrame].texture);
	sprite->setTextureRect(currenetClip->frames[currentFrame].texCoord);

}

void AnimationController::Play(std::string clipId, bool clear) // �Ű������� �Ŭ���� ������� id�� �Ѿ��
{
	if (clear)
	{
		CloarPlayQueue();
	}
	isPlaying = true;
	currenetClip = &clips[clipId];
	currentFrame = 0;
	totalFrame = currenetClip->frames.size();
	frameDuration = 1.f / currenetClip->fps;
}

void AnimationController::PlayQueue(std::string clipId)
{
	isPlaying = true;
	//push: �ش��ϴ� �ڷᱸ�� �־���
	playQueue.push(clipId);
}

void AnimationController::CloarPlayQueue()
{
	while (!playQueue.empty())
	{
		playQueue.pop();
	}
}

void AnimationController::Stop()
{
	isPlaying = false;
	CloarPlayQueue();

}

void AnimationController::GetSpeed(float sspeed)
{
	this->sspeed = sspeed;

}

bool AnimationController::IsPlaying()
{
	return false;
}
