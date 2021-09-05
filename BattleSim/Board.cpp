#include "Board.h"
#include "GameEngine.h"
#include "olcPixelGameEngine.h"


clsBoard::clsBoard(olc::PixelGameEngine* pointerToPixelGameEngine)
{
    
    pPGE = pointerToPixelGameEngine;
    std::srand(std::time(NULL));
    pHistogram = std::make_unique<clsHistogram>();

    P1_row_TopOfCards = static_cast<float>(pPGE->ScreenHeight()) * (2.0f / 3.0f);
    P2_row_TopOfCards = static_cast<float>(pPGE->ScreenHeight()) * (1.0f / 3.0f);
}

clsBoard::~clsBoard()
{
}

void clsBoard::DrawHistogram(uint8_t& dice_Sides, uint64_t& dice_RollNum)
{
    pHistogram->DrawSelf(pPGE, SimulationResults, dice_Sides);
    pPGE->SetDrawTarget(nullptr);
	pPGE->DrawStringDecal({0.0f, 10.0f}, "Dice sides: " + std::to_string(dice_Sides) + "    Press CTRL+UP/DOWN to change", olc::MAGENTA, {2.0f, 2.0f});
	pPGE->DrawStringDecal({0.0f, 50.0f}, "Dice rolls: " + std::to_string(dice_RollNum) + "   Press SHIFT+UP/DOWN to change", olc::GREEN, {2.0f, 2.0f});
	pPGE->DrawStringDecal({200.0f, 90.0f}, "Press ENTER to refresh.", olc::YELLOW, {2.0f, 2.0f});
	

	if (pPGE->GetKey(olc::ENTER).bPressed) RunDiceRollSimulation(dice_Sides, dice_RollNum);
	
	if ((pPGE->GetKey(olc::UP).bPressed) && (pPGE->GetKey(olc::CTRL).bHeld)) dice_Sides++;
	if ((pPGE->GetKey(olc::DOWN).bPressed) && (pPGE->GetKey(olc::CTRL).bHeld)) dice_Sides < 2 ? dice_Sides = 1 : dice_Sides--;

	if ((pPGE->GetKey(olc::UP).bPressed) && (pPGE->GetKey(olc::SHIFT).bHeld)) dice_RollNum = dice_RollNum * 10;
	if ((pPGE->GetKey(olc::DOWN).bPressed) && (pPGE->GetKey(olc::SHIFT).bHeld)) (dice_RollNum/10) >= 1 ? dice_RollNum = dice_RollNum / 10 : dice_RollNum = 1;

    return;
}

void clsBoard::RunDiceRollSimulation(uint8_t d_N, uint64_t totalDiceRolls)
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

void clsBoard::GenerateAllCards()
{
    //Number from 0 to 7
    int CardNum = (std::rand() % 8);
    for (int i = 0; i < CardNum; i++) 
    {
        clsCard* pCard = new clsCard(pPGE);
        Player1_Cards.push_back(pCard);
        P1_CardLeftEdgePos.push_back(GetCard_LeftEdge(CardNum, i, pCard->GetWidth()));
    }

    //Recompute board size for player 2
    CardNum = (std::rand() % 8);  
    for (int i = 0; i < CardNum; i++) 
    { 
        clsCard* pCard = new clsCard(pPGE); 
        Player2_Cards.push_back(pCard);
        P2_CardLeftEdgePos.push_back(GetCard_LeftEdge(CardNum, i, pCard->GetWidth()));
    }
}

void clsBoard::DrawAllCards()
{
    pPGE->DrawStringDecal({ 0.0f, 30.0f }, std::to_string(Player1_Cards.size()), olc::WHITE, { 2.0f, 2.0f });

    for (size_t i = 0; i < Player1_Cards.size(); i++)
    {
        Player1_Cards[i]->DrawSelf({ P1_CardLeftEdgePos[i], P1_row_TopOfCards });
    }

    pPGE->DrawStringDecal({ 0.0f, 0.0f }, std::to_string(Player2_Cards.size()), olc::WHITE, { 2.0f, 2.0f });

    for (size_t i = 0; i < Player2_Cards.size(); i++)
    {    
        Player2_Cards[i]->DrawSelf({ P2_CardLeftEdgePos[i], P2_row_TopOfCards });
    }

}

void clsBoard::DeleteAllCards()
{
    for (size_t i = 0; i < Player1_Cards.size(); i++)
    {
        delete Player1_Cards[i];
    }

    for (size_t i = 0; i < Player2_Cards.size(); i++)
    {
        delete Player2_Cards[i];
    }

    Player1_Cards.clear();
    Player2_Cards.clear();

    P1_CardLeftEdgePos.clear();
    P2_CardLeftEdgePos.clear();

}


float clsBoard::GetCard_LeftEdge(int numberOfCards, int currentCardIndex, float cardWidth)
{  
    float totalBlankSpace{ static_cast<float>(pPGE->ScreenWidth()) - (cardWidth * numberOfCards) };
    float spaceBetweenCards{ cardWidth * 0.15f };
    float totalSpaceBetweenCards{ spaceBetweenCards * (numberOfCards - 1) };
    float leftEdgeBlankSpace{ (totalBlankSpace - totalSpaceBetweenCards) / 2 };
    
    return (leftEdgeBlankSpace + (currentCardIndex * (cardWidth + spaceBetweenCards)));
};

void clsHistogram::DrawSelf(olc::PixelGameEngine* pPGE, const std::vector<int>& simulationResults, const int dice_Sides)
{
  //Loop through std::vector, if not yet initialized
  if (!HistogramInitialized)
  {
    for (int i : simulationResults) 
    {
        if (HistogramBars.find(i) == HistogramBars.end()) {HistogramBars[i] = 1;} 
        else { HistogramBars[i]++; }
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
        pPGE->DrawStringDecal({static_cast<float>(pPGE->ScreenWidth()/H_Bar_Total*H_Bar.first), static_cast<float>(pPGE->ScreenHeight()) - (static_cast<float>(pPGE->ScreenHeight())* 0.80f / static_cast<float>(H_Bar_MaxHeight) * static_cast<float>(H_Bar.second)) + 10.0f},
        std::to_string(H_Bar.second), olc::BLUE, {2.0f, 2.0f});

    }

    return;
}

void clsHistogram::ResetInit()
{
    HistogramInitialized = false;
    HistogramBars.clear();
}