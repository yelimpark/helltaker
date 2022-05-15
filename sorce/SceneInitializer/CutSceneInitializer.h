#pragma once
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

using namespace sf;

struct CutSceneData {
	char type;
	std::string name;
	std::string line;
	std::string backgroundFileName;
	std::string characterFileName;
	std::string animationClipName;
	std::string nextNode;
	std::string CGFileName;

	CutSceneData(std::vector<std::string>& row) {
		type = row[1][0];
		name = row[2];
		line = row[3];
		backgroundFileName = row[4];
		characterFileName = row[5];
		animationClipName = row[6];
		nextNode = row[7];
		CGFileName = row[8];
	}
};

struct OptionData {
	std::string line;
	std::string nextNode;

	OptionData() {

	};

	OptionData(std::vector<std::string>& row) {
		line = row[1];
		nextNode = row[2];
	}
};
