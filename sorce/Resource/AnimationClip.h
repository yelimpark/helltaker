#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

using namespace sf;

enum class AmimationLoopTypes {
	Single,
	Loop
};

struct AnimationFrame {
	Texture texture;
	IntRect texCoord;

	AnimationFrame(const Texture& tex, const IntRect& coord);
};

struct AnimationClip {
	std::string id;
	std::vector<AnimationFrame> frames;
	AmimationLoopTypes loopType;
	int fps;
};