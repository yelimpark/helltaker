#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

enum class Direction
{
	Left,
	Right,
	Up,
	Down,
};

enum class box
{
	box001,
	box003,
	box004,
	box008,
};

struct boxInfo
{
	box type;
	std::string textureFilename;
};

class Box
{
private:
	Sprite sprite;
	Direction dir;
	bool isMoving;

	float speedX;
	float speedY;

	static std::vector<boxInfo> boxes;

public:
	Box();
	void Init();
	void Moved(Direction dir);
	void Update(float dt);
	void Draw(RenderWindow& window);
};

