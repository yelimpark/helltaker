#include "AnimationHolder.h"
#include "../Utils/Utils.h"

void AnimationHolder::Init()
{
	Utils::CsvToStruct<AnimationClip>(Instance()->mapClip, "./AnimationInfo/AnimationInfo.csv");
}

AnimationClip& AnimationHolder::GetAnimation(std::string id)
{
	auto& map = Instance()->mapClip;
	auto it = map.find(id);
	if (it != map.end() && (*it).second.frames.empty()) {
		Utils::CsvToStruct<AnimationFrame>((*it).second.frames, (*it).second.path.c_str());
	}
	return map[id];
}
