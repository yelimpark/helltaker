#pragma once
#include "../Utils/Singleton.h"
#include <SFML/Graphics.hpp>
#include <map>

using namespace sf;
using namespace std;

class TextureHolder : public Singleton<TextureHolder> 
{
private:
	map<string, Texture> mapTexture;

public:
	static Texture& GetTexture(string filename);
};