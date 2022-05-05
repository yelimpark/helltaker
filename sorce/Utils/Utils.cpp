#include "Utils.h"

std::random_device Utils::rd;
std::mt19937 Utils::gen(rd());

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

int Utils::RandomRange(int min, int max)
{
	return gen() % (max - min) + min;
}

bool Utils::RandomBool()
{
	return (gen() % 2 == 1) ? true : false;
}

Vector2f Utils::NomalizeVector(Vector2f vector)
{
	float length = GetLength(vector);

	if (length > 0) {
		vector /= length;
	}

	return vector;
}

bool Utils::IsPointInArea(const Vector2f& point, float left, float top, float width, float height)
{
	FloatRect area;
	area.left = left;
	area.top = top;
	area.width = width;
	area.height = height;

	return area.contains(point);
}

bool Utils::IsRectInArea(const FloatRect& rect, float left, float top, float width, float height)
{
	FloatRect area;
	area.left = left;
	area.top = top;
	area.width = width;
	area.height = height;

	return area.intersects(rect);
}

float Utils::GetLength(const Vector2f& vector)
{
	return sqrt(vector.x * vector.x + vector.y * vector.y);
}

float Utils::GetAngle(const Vector2f& from, const Vector2f& to)
{
	Vector2f dir = to - from;
	float radian = atan2(dir.y, dir.x);
	return radian * 180.f / 3.141592f;
}
