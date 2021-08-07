#define OLC_PGE_APPLICATION
#include <cstdlib>
#include <ctime>
#include <memory>
#include "olcPixelGameEngine.h"
#include "GameEngine.h"
#include "Card.h"
#include "Board.h"


int main()
{
	//Get new seed for rand
	std::srand(static_cast<uint32_t>(std::time(NULL)));

	clsEngine demo;
	if (demo.Construct(1920, 1080, 1, 1))
		demo.Start();
	return 0;
}