#include "Utils.h"
#include "../SceneInitializer/StageSceneInitializer.h"
#include "../Utils/GameVal.h"
#include <string>

void Utils::SetOrigin(Sprite& sprite, Pivots preset)
{
	SetOrigin(sprite, sprite.getLocalBounds(), preset);
}

void Utils::SetOrigin(Shape& shape, Pivots preset)
{
	SetOrigin(shape, shape.getLocalBounds(), preset);
}

void Utils::SetOrigin(Text& text, Pivots preset)
{
	SetOrigin(text, text.getLocalBounds(), preset);
}

void Utils::SetOrigin(Transformable& tr, FloatRect bounds, Pivots preset)
{
	switch (preset)
	{
	case Pivots::LeftTop:
		tr.setOrigin(0, 0);
		break;
	case Pivots::CenterTop:
		tr.setOrigin(bounds.width * 0.5f, 0);
		break;
	case Pivots::RightTop:
		tr.setOrigin(bounds.width, 0);
		break;
	case Pivots::LeftMiddle:
		tr.setOrigin(0, bounds.height * 0.5f);
		break;
	case Pivots::Center:
		tr.setOrigin(bounds.width * 0.5f, bounds.height * 0.5f);
		break;
	case Pivots::RightMiddle:
		tr.setOrigin(bounds.width, bounds.height * 0.5f);
		break;
	case Pivots::LeftBottom:
		tr.setOrigin(0, bounds.height);
		break;
	case Pivots::CenterBottom:
		tr.setOrigin(bounds.width * 0.5f, bounds.height);
		break;
	case Pivots::RightBottom:
		tr.setOrigin(bounds.width, bounds.height);
		break;
	default:
		break;
	}
}

Vector2i Utils::PosToIdx(Vector2f& pos)
{
	rapidcsv::Document csvData("./LevelInfo/LevelInfo.csv", rapidcsv::LabelParams(1, 0));

	int leftMargin = csvData.GetCell<int>("marginLeft", std::to_string(GameVal::level));
	int topMargin = csvData.GetCell<int>("marginTop", std::to_string(GameVal::level));
	int TILE_SIZE = 100;

	Vector2i idx;
	idx.x = (pos.x - leftMargin - TILE_SIZE / 20) / TILE_SIZE;
	idx.y = (pos.y - topMargin - TILE_SIZE / 20) / TILE_SIZE;
	return idx;
}

Vector2f Utils::IdxToPos(int i, int j)
{
	rapidcsv::Document csvData("./LevelInfo/LevelInfo.csv", rapidcsv::LabelParams(1, 0));

	int leftMargin = csvData.GetCell<int>("marginLeft", std::to_string(GameVal::level));
	int topMargin = csvData.GetCell<int>("marginTop", std::to_string(GameVal::level));
	int TILE_SIZE = 100;

	Vector2f pos;
	pos.x = j * TILE_SIZE + TILE_SIZE / 2 + leftMargin;
	pos.y = i * TILE_SIZE + TILE_SIZE / 2 + topMargin;
	return pos;
}
