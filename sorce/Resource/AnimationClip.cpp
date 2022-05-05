#include "AnimationClip.h"
#include "../Resource/TextureHolder.h"
#include <iostream>

AnimationFrame::AnimationFrame(const Texture& tex, const IntRect& coord)
{
	texture = tex;
	texCoord = coord;
}

AnimationFrame::AnimationFrame(std::vector<std::string>& row)
{
	texture = TextureHolder::GetTexture(row[0]);
	texCoord = IntRect(stoi(row[1]), stoi(row[2]), stoi(row[3]), stoi(row[4]));
}

AnimationClip::AnimationClip()
{
	loopType = AmimationLoopTypes::Single;
	fps = 0;
}

AnimationClip::AnimationClip(std::vector<std::string>& row)
{
	id = row[0];
	fps = stoi(row[1]);
	loopType = (AmimationLoopTypes) stoi(row[2]);
	path = row[3];
}
