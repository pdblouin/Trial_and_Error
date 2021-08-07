#pragma once

#include <array>
#include "Card.h"
#include "olcPixelGameEngine.h"

class clsBoard
{
public:

	clsBoard();
	~clsBoard();

private:
	std::array<clsCard*, 7> friendlyCards;
	std::array<clsCard*, 7> enemyCards;

private:

	void runSimulation(); //Maybe custom log class type? To log results?

};