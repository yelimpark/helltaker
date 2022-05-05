#include "AnimationController.h"
#include "AnimationHolder.h"

AnimationController::AnimationController()
	:clips(), currentClip(nullptr), isPlaying(false),
	currentFrame(0), totalFrame(0), frameDuration(0.f),
	accumTime(0.f), sprite(nullptr)
{
}

void AnimationController::SetTarget(Sprite* sprite)
{
	this->sprite = sprite;
}

void AnimationController::AddClip(std::string id)
{
	AnimationClip newClip = AnimationHolder::GetAnimation(id);
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
			Play(que.front(), false);
			que.pop_front();
			return;
		}

		switch (currentClip->loopType)
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

	sprite->setTexture(currentClip->frames[currentFrame].texture);
	sprite->setTextureRect(currentClip->frames[currentFrame].texCoord);
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
	currentClip = &clips[clipId];
	currentFrame = 0;
	totalFrame = currentClip->frames.size();
	frameDuration = 1.f / currentClip->fps;
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

bool AnimationController::IsAnimationEnd()
{
	return currentFrame == totalFrame;
}
