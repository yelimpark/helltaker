#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

using namespace sf;

enum class AnimationLoopTypes
{
	Single,
	Loop,
};

struct AnimationFrame
{
	Texture texture;
	IntRect texCoord;

	AnimationFrame(const Texture tex, const IntRect& coord);

};

struct AnimationClip
{
	std::string id; //id에 해당하는 문자열 사용
	std::vector<AnimationFrame> frames; // 벡터부분 공부
	AnimationLoopTypes loopTypes;
	int fps; //1초당 몇번 애니매이션 재생할건지
};

