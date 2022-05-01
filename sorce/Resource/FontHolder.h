#pragma once
#include "../Utils/Singleton.h"
#include <SFML/Graphics.hpp>
#include <map>

using namespace sf;
using namespace std;

class FontHolder : public Singleton<FontHolder>
{
private:
	map<string, Font> mapFont;

public:
	static Font& GetFont(string filename);
};