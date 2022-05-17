#include "./GameVal.h"

int GameVal::level;
int GameVal::cutSceneIdx;
int GameVal::musicSound;
int GameVal::effectSound;
std::string GameVal::language = "";

void GameVal::Init()
{
	level = 1;

	cutSceneIdx = 0;

	musicSound = 1;

	effectSound = 1;
} 