#include "./SoundHolder.h"

Sound& SoundHolder::GetSound(string filename)
{
	auto& map = Instance()->mapSound;
	auto it = map.find(filename);
	if (it == map.end()) {
		auto& mySound = map[filename];
		mySound.soundBuffer.loadFromFile(filename);
		mySound.sound.setBuffer(mySound.soundBuffer);
	}

	return map[filename].sound;
}
