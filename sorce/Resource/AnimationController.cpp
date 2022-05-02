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
		return; //false면 업데이트 x
	}

	accumTime += dt * sspeed; //dt -> 지나간시간

	if (accumTime < frameDuration)
	{
		return;
	} // 작으면 교체할 타임이 아님

	accumTime = 0.f;
	++currentFrame;
	if (currentFrame >= totalFrame) //마지막 프레임 정하고나서 다음프레임 정해줌
	{
		if (playQueue.empty()) //queue가 비워져있으면 기존처럼 재생
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
		else//queue가 비워져있지않으면 프레임 삭제후 다음 프레임
		{
			// pop(빼는것)
			std::string nextClip = playQueue.front();
			playQueue.pop();
			Play(nextClip, false);
		}
	}

	sprite->setTexture(currenetClip->frames[currentFrame].texture);
	sprite->setTextureRect(currenetClip->frames[currentFrame].texCoord);

}

void AnimationController::Play(std::string clipId, bool clear) // 매개변수로 어떤클립이 재생될지 id가 넘어옴
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
	//push: 해당하는 자료구조 넣어줌
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
