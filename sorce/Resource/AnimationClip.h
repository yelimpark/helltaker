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

	AnimationFrame(std::vector<std::string>& row);
};

struct AnimationClip {
	std::string id;
	std::vector<AnimationFrame> frames;
	AmimationLoopTypes loopType;
	int fps;
	std::string path;

	AnimationClip();

	AnimationClip(std::vector<std::string>& row);
};