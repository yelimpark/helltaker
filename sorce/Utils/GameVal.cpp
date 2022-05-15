#include "./GameVal.h"

int GameVal::level;
int GameVal::cutSceneIdx;
int GameVal::musicSound;
int GameVal::effectSound;

void GameVal::Init()
{
	level = 1;

	cutSceneIdx = -1;

	musicSound = 1;

	effectSound = 1;
}