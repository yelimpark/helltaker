#include "./GameVal.h"

int GameVal::level;
int GameVal::cutSceneIdx;
int GameVal::musicSound;
int GameVal::effectSound;

void GameVal::Init()
{
	level = 4;

	cutSceneIdx = 0;

	musicSound = 1;

	effectSound = 1;
}