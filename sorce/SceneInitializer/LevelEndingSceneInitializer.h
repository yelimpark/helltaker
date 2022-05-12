#pragma once
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

using namespace sf;

struct LevelEndngData {
	char type;
	std::string name;
	std::string line;
	std::string backgroundFileName;
	std::string characterFileName;
	std::string animationClipName;
	std::string CGFileName;

	LevelEndngData(std::vector<std::string>& row) {
		type = row[1][0];
		name = row[2];
		line = row[3];
		backgroundFileName = row[4];
		characterFileName = row[5];
		animationClipName = row[6];
		CGFileName = row[7];
	}
};

struct OptionData {
	bool isBad;
	std::string line;

	OptionData(std::vector<std::string>& row) {
		isBad = stoi(row[1]);
		line = row[2];
	}
};
