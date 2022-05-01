#include "./TextureHolder.h"

Texture& TextureHolder::GetTexture(string filename)
{
	auto& map = Instance()->mapTexture;
	auto it = map.find(filename);
	if (it == map.end()) {
		auto& texture = map[filename];
		texture.loadFromFile(filename);
	}

	return map[filename];
}
