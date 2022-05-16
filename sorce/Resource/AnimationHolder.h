#pragma once
#include "../Utils/Singleton.h"
#include "../Resource/AnimationClip.h"
#include <SFML/Graphics.hpp>
#include <map>

using namespace sf;

class AnimationHolder : public Singleton<AnimationHolder>
{
private:
	std::map<std::string, AnimationClip> mapClip;

public:
	static void Init();

	static AnimationClip& GetAnimation(std::string id);
};