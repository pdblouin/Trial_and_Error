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

void clsBoard::DrawHistogram()
{
    pHistogram->DrawSelf(pPGE);
    return;
}

void clsHistogram::DrawSelf(olc::PixelGameEngine* pPGE)
{
  //Run simulation (hopefully in another thread when I'm not a drooling noob, but once per frame for now)
  clsHistogram::runSimulation(SimulationResults);

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

  pPGE->SetDrawTarget(nullptr);
  pPGE->Clear(olc::BLANK);

  //Loop through map and draw bars
  int H_Bar_Total = HistogramBars.size();
  long long H_Bar_MaxHeight = 1;

  for (auto const& H_Bar : HistogramBars)
{
    if (H_Bar_MaxHeight < H_Bar.second) H_Bar_MaxHeight = H_Bar.second;
    
    //Draw bar
    pPGE->SetDrawTarget(1);
    pPGE->EnableLayer(1,true);
    pPGE->FillRectDecal({static_cast<float>(pPGE->ScreenWidth()/H_Bar_Total*H_Bar.first), static_cast<float>(pPGE->ScreenHeight())}, 
                   {static_cast<float>((pPGE->ScreenWidth()/H_Bar_Total)*0.66f), 
                   (-(static_cast<float>(pPGE->ScreenHeight()) / static_cast<float>(H_Bar_MaxHeight) * static_cast<float>(H_Bar.second)))},
                   olc::WHITE);
    
    //Draw text
    
    pPGE->SetDrawTarget(nullptr);
    pPGE->EnableLayer(0 , true);
    pPGE->DrawStringDecal({static_cast<float>(pPGE->ScreenWidth()/H_Bar_Total*H_Bar.first), static_cast<float>(pPGE->ScreenHeight())*0.9f},
    std::to_string(H_Bar.first + 1), olc::BLACK, {3.0f, 3.0f});
    pPGE->DrawStringDecal({static_cast<float>(pPGE->ScreenWidth()/H_Bar_Total*H_Bar.first), static_cast<float>(pPGE->ScreenHeight())*0.7f},
    std::to_string(H_Bar.second / 100), olc::BLACK, {2.0f, 2.0f});

}

    return;
}

void clsHistogram::runSimulation(std::vector<int>& SimulationResults)
{
    int x = std::rand() % 6;
    SimulationResults.push_back(x);

    return;

}