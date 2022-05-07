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

	LevelData() {
		lastTurn = 0;
	};

	LevelData(std::vector<std::string>& row) {
		BgFilename = row[1];
		bgPos.x = stoi(row[2]);
		bgPos.y = stoi(row[3]);
		lastTurn = stoi(row[4]);
		MapFilePath = row[5];
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
};

struct SkullData
{
	int x;
	int y;

	SkullData(std::vector<std::string>& row)
	{
		x = stoi(row[1]);
		y = stoi(row[2]);
	}
};

