#include "AnimationHolder.h"
#include "../Utils/Utils.h"

void AnimationHolder::Init()
{
	Utils::CsvToStruct<AnimationClip>(Instance()->mapClip, "./AnimationInfo/AnmationInfo.csv");
}

AnimationClip& AnimationHolder::GetAnimation(std::string filename)
{
	auto& map = Instance()->mapClip;
	auto it = map.find(filename);
	if (it != map.end() && (*it).second.frames.empty()) {
		Utils::CsvToStruct<AnimationFrame>((*it).second.frames, "./AnimationInfo/fire.csv");
	}
	return map[filename];
}
