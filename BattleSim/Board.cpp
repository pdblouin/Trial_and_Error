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

void clsBoard::DrawHistogram(clsHistogram* pHistogram, olc::PixelGameEngine* pPGE)
{
    pHistogram->DrawSelf(pPGE);
}

void clsHistogram::DrawSelf(olc::PixelGameEngine* pPGE)
{
  //Run simulation (hopefully in another thread when I'm not a drooling noob, but once per frame for now)
  clsHistogram::runSimulation(SimulationResults);

  //Loop through std::vector
  for (std::vector<int>::iterator it = std::begin (SimulationResults); it != std::end (SimulationResults); ++it) 
  {

    //Get 
    
  }

}

void clsHistogram::runSimulation(std::vector<int>& SimulationResults)
{
    int x = std::rand() % 15;
    SimulationResults.push_back(x);

}