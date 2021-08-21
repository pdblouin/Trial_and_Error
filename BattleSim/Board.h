#pragma once

#include "olcPixelGameEngine.h"

#include <vector>
#include <random>
#include <time.h>
#include "Card.h"

class clsBoard
{
public:

	clsBoard(olc::PixelGameEngine* pointerToPixelGameEngine);
	~clsBoard();

private:

	olc::PixelGameEngine* pPGE { nullptr };

	std::unique_ptr<clsHistogram> pHistogram { nullptr };

public:

	void DrawHistogram(clsHistogram* pHistogram, olc::PixelGameEngine* pge);

};

class clsHistogram
{
private:
	std::vector<int> SimulationResults;

public:
	void DrawSelf(olc::PixelGameEngine* pPGE);
	void runSimulation(std::vector<int>& SimulationResults);

};

struct HistogramData
{
public:

	result

};