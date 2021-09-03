#pragma once

#include <random>
#include <string>

#include "olcPixelGameEngine.h"

class clsCard
{
public:


private:
    
    olc::PixelGameEngine* pPGE;

    const std::string CardPath{ "./Card_Test.png" };
    olc::Sprite* pCard_Sprite{ nullptr };
    olc::Decal* pCard_Decal{ nullptr };
    float scaleFactor{ 1.0f };

    olc::vf2d m_Position{0.0f, 0.0f};
    int m_AP{ -1 }, m_HP{ -1 }, m_Tier{ -1 };

public: 
    clsCard(olc::PixelGameEngine* pPGE);
    ~clsCard();
    void DrawSelf(olc::vf2d cardTopLeftPos);
    float GetWidth();
    
private:

    float GetScaleFactor();
    

};
