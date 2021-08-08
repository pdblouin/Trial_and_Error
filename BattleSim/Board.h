#pragma once

#include "olcPixelGameEngine.h"

#include <array>
#include "Card.h"

class clsBoard
{
public:

	clsBoard();
	~clsBoard();

private:
	std::array<clsCard*, 7> friendlyCards{ nullptr };
	std::array<clsCard*, 7> enemyCards{ nullptr };

private:

	void runSimulation(); //Maybe custom log class type? To log results?

};