#pragma once
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

using namespace sf;

struct LevelData {
	std::string BgFilename;
	int BgPosX;
	int BgPosY;
	int lastTurn;

	LevelData() {
		BgPosX = 0;
		BgPosY = 0;
		lastTurn = 0;
	};

	LevelData(std::vector<std::string>& row) {
		BgFilename = row[1];
		BgPosX = stoi(row[2]);
		BgPosY = stoi(row[3]);
		lastTurn = stoi(row[4]);
	};
};

struct FlameBaseData {
	int x;
	int y;

	FlameBaseData(std::vector<std::string>& row) {
		x = stoi(row[1]);
		y = stoi(row[2]);
	};
};

struct boxInfo
{
	std::string textureFilename;
	Vector2f position;
};

