#include "AnimationHolder.h"
#include "../Utils/Utils.h"

void AnimationHolder::Init()
{
	Utills::CsvToStruct<AnimationClip>(Instance()->mapClip, "./AnimationInfo/AnmationInfo.csv");
}

AnimationClip& AnimationHolder::GetAnimation(std::string filename)
{
	auto& map = Instance()->mapClip;
	auto it = map.find(filename);
	if (it != map.end() && (*it).second.frames.empty()) {
		Utills::CsvToStruct<AnimationFrame>((*it).second.frames, "./AnimationInfo/fire.csv");
	}
	return map[filename];
}
