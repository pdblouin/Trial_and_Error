#pragma once

#include "olcPixelGameEngine.h"

#include <vector>
#include <array>
#include <random>
#include <time.h>
#include "Card.h"

class clsHistogram
{
private:
	std::map<int, int> HistogramBars;
	bool HistogramInitialized {false};
	

public:
	void DrawSelf(olc::PixelGameEngine* pPGE, const std::vector<int>& simulationResults, const int dice_sides);
	void ResetInit();
};

class clsBoard
{
public:

	clsBoard(olc::PixelGameEngine* pointerToPixelGameEngine);
	~clsBoard();
private:
	
	olc::PixelGameEngine* pPGE { nullptr };

	std::vector<int> SimulationResults;
	std::unique_ptr<clsHistogram> pHistogram { nullptr };

	std::unique_ptr<clsCard> Player1_Cards[7];
	std::unique_ptr<clsCard> Player2_Cards[7];

public:
	void RunDiceRollSimulation(int d_N, int totalDiceRolls);
	void DrawHistogram(int& dice_Sides, long long& dice_RollNum);
	void GenerateAllCards();
	

private:
	

};