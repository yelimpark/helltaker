#include "./GameVal.h"

int GameVal::level;
int GameVal::musicSound;
int GameVal::effectSound;

void GameVal::Init()
{
	level = 0;

	musicSound = 1;

	effectSound = 1;
}