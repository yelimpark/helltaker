#include "AnimationHolder.h"
#include "../Utils/Utils.h"

void AnimationHolder::Init()
{
	Utills::CsvToStruct<AnimationClip>(Instance()->mapClip, "./AnimationInfo/AnmationInfo.csv");
}

AnimationClip& AnimationHolder::GetAnimation(std::string id)
{
	auto& map = Instance()->mapClip;
	auto it = map.find(id);
	if (it != map.end() && (*it).second.frames.empty()) {
		Utills::CsvToStruct<AnimationFrame>((*it).second.frames, (*it).second.path.c_str());
	}
	return map[id];
}
