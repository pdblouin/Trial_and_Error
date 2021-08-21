#pragma once

#include "olcPixelGameEngine.h"

#include <vector>
#include <random>
#include <time.h>
#include "Card.h"

class clsHistogram
{
private:
	std::vector<int> SimulationResults;
	std::map<int, int> HistogramBars;

public:
	void DrawSelf(olc::PixelGameEngine* pPGE);
	void runSimulation(std::vector<int>& SimulationResults);

};

class clsBoard
{
public:

	clsBoard(olc::PixelGameEngine* pointerToPixelGameEngine);
	~clsBoard();
private:
	olc::PixelGameEngine* pPGE { nullptr };
	std::unique_ptr<clsHistogram> pHistogram { nullptr };

public:

	void DrawHistogram();

};