#include "./GameVal.h"

int GameVal::level;
int GameVal::cutSceneIdx;
int GameVal::musicSound;
int GameVal::effectSound;

void GameVal::Init()
{
	level = 2;

	cutSceneIdx = 0;

	musicSound = 1;

	effectSound = 1;
}