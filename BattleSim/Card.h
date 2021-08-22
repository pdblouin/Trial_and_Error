#pragma once

#include <random>

#include "olcPixelGameEngine.h"

class clsCard
{
    public: 
        

    private: 

        olc::PixelGameEngine* pPGE;

        olc::vf2d m_Position{0.0f, 0.0f};
        int m_AP, m_HP, m_Tier;

    public: 
        clsCard(olc::PixelGameEngine* pPGE, bool setRandomStats = true);
        ~clsCard();
        void DrawSelf();
    
    private:

};
