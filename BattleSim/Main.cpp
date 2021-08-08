#define OLC_PGE_APPLICATION

#include "olcPixelGameEngine.h"

#include <cstdlib>
#include <memory>

#include "GameEngine.h"
#include "Card.h"
#include "Board.h"


int main()
{
	clsEngine gameInstance;
	if (gameInstance.Construct(1280, 720, 1, 1))
		gameInstance.Start();

	return 0;
}