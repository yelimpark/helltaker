#pragma once
#include <SFML/Graphics.hpp>
#include <random>

using namespace sf;

enum class Pivots {
	LeftTop,
	CenterTop,
	RightTop,
	LeftMiddle,
	Center,
	RightMiddle,
	LeftBottom,
	CenterBottom,
	RightBottom
};

class Utils {
private:
	static std::random_device rd;
	static std::mt19937 gen;

public:
	static void SetOrigin(Sprite& sprite, Pivots preset);

	static void SetOrigin(Shape& shape, Pivots preset);

	static void SetOrigin(Text& text, Pivots preset);

	static void SetOrigin(Transformable& tr, FloatRect bounds, Pivots preset);

	static int RandomRange(int min, int max);

	static bool RandomBool();

	static Vector2f NomalizeVector(Vector2f vector);

	static bool IsPointInArea(const Vector2f& point, float left, float top, float width, float height);

	static bool IsRectInArea(const FloatRect& rect, float left, float top, float width, float height);

	static float GetLength(const Vector2f& vector);

	static float GetAngle(const Vector2f& from, const Vector2f& to);
};
