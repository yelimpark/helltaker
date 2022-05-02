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
	std::string id; //id�� �ش��ϴ� ���ڿ� ���
	std::vector<AnimationFrame> frames; // ���ͺκ� ����
	AnimationLoopTypes loopTypes;
	int fps; //1�ʴ� ��� �ִϸ��̼� ����Ұ���
};

