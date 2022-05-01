#include "./FontHolder.h"

Font& FontHolder::GetFont(string filename)
{
	auto& map = Instance()->mapFont;
	auto it = map.find(filename);
	if (it == map.end()) {
		auto& font = map[filename];
		font.loadFromFile(filename);
	}

	return map[filename];
}