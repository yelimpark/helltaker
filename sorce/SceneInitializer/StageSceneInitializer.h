#pragma once
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

using namespace sf;

struct LevelData {
	std::string BgFilename;
	Vector2f bgPos;
	int lastTurn;
	std::string MapFilePath;
	std::string chapter;
	int marginLeft;
	int marginTop;
	std::string demonName;
	std::string ClawMapFilePath;

	LevelData() {
		lastTurn = 0;
		marginLeft = 0;
		marginTop = 0;
	};

	LevelData(std::vector<std::string>& row) {
		BgFilename = row[1];
		bgPos.x = stoi(row[2]);
		bgPos.y = stoi(row[3]);
		lastTurn = stoi(row[4]);
		MapFilePath = row[5];
		chapter = row[6];
		marginLeft = stoi(row[7]);
		marginTop = stoi(row[8]);
		demonName = row[9];
		ClawMapFilePath = row[10];
	};
};

struct FlameData {
	Vector2f position;

	FlameData(std::vector<std::string>& row) {
		position.x = stoi(row[1]);
		position.y = stoi(row[2]);
	};
};

struct FlameBaseData {
	Vector2f position;
	std::string texturefile;

	FlameBaseData(std::vector<std::string>& row) {
		position.x = stoi(row[1]);
		position.y = stoi(row[2]);
		texturefile = row[3];
	};
};

struct BoxData
{
	std::string textureFilename;
	Vector2f position;

	BoxData(std::vector<std::string>& row) {
		textureFilename = row[1];
	}
};
