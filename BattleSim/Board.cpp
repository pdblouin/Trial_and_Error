#include "Board.h"
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

void clsBoard::DrawHistogram()
{
    pHistogram->DrawSelf(pPGE);
    return;
}

void clsHistogram::DrawSelf(olc::PixelGameEngine* pPGE)
{
  //Run simulation (hopefully in another thread when I'm not a drooling noob, but once per frame for now)
  clsHistogram::runSimulation(SimulationResults);

  pPGE->DrawStringDecal({0.0f, 0.0f}, std::to_string(SimulationResults.size()),olc::YELLOW,{5.0f, 5.0f});

  //Loop through std::vector
  for (int i : SimulationResults) 
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

  //Loop through map and draw bars
  int H_Bar_Total = HistogramBars.size();
  int H_Bar_MaxHeight = 1;

  pPGE->DrawStringDecal({0.0f, 40.0f}, std::to_string(HistogramBars.size()),olc::YELLOW,{5.0f, 5.0f});

  for (auto const& H_Bar : HistogramBars)
{
    if (H_Bar_MaxHeight < H_Bar.second) H_Bar_MaxHeight = H_Bar.second;
    
    pPGE->FillRectDecal({static_cast<float>(pPGE->ScreenWidth()/H_Bar_Total*H_Bar.first), static_cast<float>(pPGE->ScreenHeight())}, 
                   {static_cast<float>(pPGE->ScreenWidth()/H_Bar_Total), static_cast<float>(-(pPGE->ScreenHeight()/H_Bar_MaxHeight*H_Bar.second))},
                   olc::WHITE);
}

    return;
}

void clsHistogram::runSimulation(std::vector<int>& SimulationResults)
{
    int x = std::rand() % 5;
    SimulationResults.push_back(x);

    return;

}