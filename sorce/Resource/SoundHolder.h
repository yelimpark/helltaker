#pragma once
#include "../Utils/Singleton.h"
#include <SFML/Audio.hpp>
#include <map>

using namespace sf;
using namespace std;

struct MySound {
	SoundBuffer soundBuffer;
	Sound sound;
};

class SoundHolder : public Singleton<SoundHolder>
{
private:
	map<string, MySound> mapSound;

public:
	static Sound& GetSound(string filename);
};