#include "Board.h"
#include "olcPixelGameEngine.h"


clsBoard::clsBoard(olc::PixelGameEngine* pointerToPixelGameEngine)
{
  /*
  Board constructor should load all cards
  Maybe based off of some init file? Ideally user chooses cards to run simulation    
  */

    pPGE = pointerToPixelGameEngine;
}

clsBoard::~clsBoard()
{
    
}

void clsBoard::runSimulation()
{
    //Add stuff here later
}

void clsBoard::Setup()
{
  uint8_t newLayer{ pPGE->CreateLayer() };

  pPGE->EnableLayer(newLayer, true);

  pPGE->SetDrawTarget(newLayer);
  pPGE->DrawStringDecal({static_cast<float>(pPGE->ScreenWidth()), static_cast<float>(pPGE->ScreenHeight())}, "Test", olc::BLACK, {3.0f, 3.0f});
  pPGE->DrawStringDecal({static_cast<float>(pPGE->ScreenWidth()), static_cast<float>(pPGE->ScreenHeight())}, "Test", olc::WHITE, {3.0f, 3.0f});

  pPGE->SetDrawTarget(nullptr);

  return;
}

void clsBoard::DrawTest()
{

    pPGE->DrawStringDecal({static_cast<float>(pPGE->ScreenWidth()), static_cast<float>(pPGE->ScreenHeight())}, "Test", olc::BLACK, {3.0f, 3.0f});

}