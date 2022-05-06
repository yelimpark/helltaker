#pragma once
#include <vector>
#include <string>

struct LevelData {
	std::string BgFilename;
	int BgPosX;
	int BgPosY;
	int lastTurn;
	std::string MapFilePath;

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
		MapFilePath = row[5];
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

