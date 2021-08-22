#include "Board.h"
#include "GameEngine.h"
#include "olcPixelGameEngine.h"


clsBoard::clsBoard(olc::PixelGameEngine* pointerToPixelGameEngine)
{
    
    pPGE = pointerToPixelGameEngine;
    std::srand(std::time(NULL));
    pHistogram = std::make_unique<clsHistogram>();
}

clsBoard::~clsBoard()
{
}

void clsBoard::DrawHistogram(const int dice_Sides)
{
    pHistogram->DrawSelf(pPGE, SimulationResults, dice_Sides);
    return;
}

void clsBoard::RunDiceRollSimulation(int d_N, int totalDiceRolls)
{
    SimulationResults.clear();

    for (int i = 0; i < totalDiceRolls; i++)
    {
        int x = std::rand() % d_N;
        SimulationResults.push_back(x);
    }

    pHistogram->ResetInit();

    return;

}

void clsHistogram::DrawSelf(olc::PixelGameEngine* pPGE, const std::vector<int>& simulationResults, const int dice_Sides)
{
  //Loop through std::vector, if not yet initialized
  if (!HistogramInitialized)
  {
    for (int i : simulationResults) 
    {

        if (HistogramBars.find(i) == HistogramBars.end())
        {
            HistogramBars[i] = 1;
        } 
        else
        {
            HistogramBars[i]++;
        }
    }

    HistogramInitialized = true;
  
  }

  pPGE->SetDrawTarget(nullptr);
  pPGE->Clear(olc::BLANK);

  //Loop through map and draw bars
  int H_Bar_Total = dice_Sides;
  long long H_Bar_MaxHeight = 1;

  //Get max height to normalize tallest bar
    for (auto const& H_Bar : HistogramBars)
    {
        if (H_Bar_MaxHeight < H_Bar.second) H_Bar_MaxHeight = H_Bar.second;
    }

//Then draw histogram
    for (auto const& H_Bar : HistogramBars)
    {    
        //Draw bar
        pPGE->SetDrawTarget(1);
        pPGE->EnableLayer(1,true);
        pPGE->FillRectDecal({static_cast<float>(pPGE->ScreenWidth()/H_Bar_Total*H_Bar.first), static_cast<float>(pPGE->ScreenHeight())}, 
                    {static_cast<float>((pPGE->ScreenWidth()/H_Bar_Total)*0.66f), 
                    (-(static_cast<float>(pPGE->ScreenHeight()) * 0.80f / static_cast<float>(H_Bar_MaxHeight) * static_cast<float>(H_Bar.second)))},
                    olc::WHITE);
        
        //Draw text
        pPGE->SetDrawTarget(nullptr);
        pPGE->EnableLayer(0 , true);
        pPGE->DrawStringDecal({static_cast<float>(pPGE->ScreenWidth()/H_Bar_Total*H_Bar.first), static_cast<float>(pPGE->ScreenHeight())*0.9f},
        std::to_string(H_Bar.first + 1), olc::BLACK, {3.0f, 3.0f});
        pPGE->DrawStringDecal({static_cast<float>(pPGE->ScreenWidth()/H_Bar_Total*H_Bar.first), static_cast<float>(pPGE->ScreenHeight())*0.7f},
        std::to_string(H_Bar.second), olc::BLUE, {2.0f, 2.0f});

    }

    return;
}

void clsHistogram::ResetInit()
{
    HistogramInitialized = false;
    HistogramBars.clear();
}