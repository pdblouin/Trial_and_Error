#pragma once

#include "olcPixelGameEngine.h"

#include <array>
#include "Card.h"

class clsBoard
{
public:

	clsBoard(olc::PixelGameEngine* pointerToPixelGameEngine);
	~clsBoard();

private:

	olc::PixelGameEngine* pPGE { nullptr };

	std::array<clsCard*, 7> friendlyCards{ nullptr };
	std::array<clsCard*, 7> enemyCards{ nullptr };

public:

	void Setup();
	void DrawTest();

private:

	void runSimulation(); //Maybe custom log class type? To log results?

};