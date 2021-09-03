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

	std::vector<clsCard*> Player1_Cards;
	std::vector<clsCard*> Player2_Cards;

	std::vector<float> P1_CardLeftEdgePos;
	std::vector<float> P2_CardLeftEdgePos;

	float P1_row_TopOfCards{ 0.0f }, P2_row_TopOfCards{ 0.0f };

public:
	void RunDiceRollSimulation(int d_N, int totalDiceRolls);
	void DrawHistogram(int& dice_Sides, long long& dice_RollNum);
	void GenerateAllCards();
	void DrawAllCards();
	void DeleteAllCards();
	

private:
	
	float GetCard_LeftEdge(int numberOfCards, int currentCardIndex, float cardWidth);

};