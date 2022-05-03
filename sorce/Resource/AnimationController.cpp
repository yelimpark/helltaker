#include "AnimationController.h"

AnimationController::AnimationController()
	:clips(), currentCltp(nullptr), isPlaying(false),
	currentFrame(0), totalFrame(0), frameDuration(0.f),
	accumTime(0.f), sprite(nullptr)
{
}

void AnimationController::SetTarget(Sprite* sprite)
{
	this->sprite = sprite;
}

void AnimationController::AddClip(const AnimationClip& newClip)
{
	if (clips.find(newClip.id) == clips.end()) {
		clips[newClip.id] = newClip;
	}
}

void AnimationController::Update(float dt)
{
	if (!isPlaying) return;

	accumTime += dt;
	if (accumTime < frameDuration) return;

	accumTime = 0.f;
	++currentFrame;

	if (currentFrame >= totalFrame) {
		if (!que.empty()) {
			currentCltp = &clips[que.front()];
			que.pop_front();
			currentFrame = 0;
			totalFrame = currentCltp->frames.size();
			frameDuration = 1.f / currentCltp->fps;
			return;
		}

		switch (currentCltp->loopType)
		{
		case AmimationLoopTypes::Single:
			currentFrame = totalFrame - 1;
			break;

		case AmimationLoopTypes::Loop:
			currentFrame = 0;
			break;
		default:
			break;
		}
	}

	sprite->setTexture(currentCltp->frames[currentFrame].texture);
	sprite->setTextureRect(currentCltp->frames[currentFrame].texCoord);

}

void AnimationController::PlayQue(std::string clipId)
{
	if (!que.empty() && que.back() == clipId) return;
	que.push_back(clipId);
	isPlaying = true;
}

void AnimationController::Play(std::string clipId, bool clear)
{
	isPlaying = true;
	currentCltp = &clips[clipId];
	currentFrame = 0;
	totalFrame = currentCltp->frames.size();
	frameDuration = 1.f / currentCltp->fps;
	if (clear) {
		que.clear();
	}
}

void AnimationController::stop()
{
	isPlaying = false;
	que.clear();
}

bool AnimationController::IsPlaying()
{
	return isPlaying;
}

void AnimationController::changeSpeed(float speed)
{
	speed = 1.f / speed;
	frameDuration = speed / currentCltp->fps;
}

bool AnimationController::IsAnimationEnd()
{
	return currentFrame == totalFrame;
}
