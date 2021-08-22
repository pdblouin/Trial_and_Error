#pragma once

#include <random>

#include "olcPixelGameEngine.h"

class clsCard
{
    public: 
        

    private: 

        olc::vi2d m_Position;
        bool m_isFriendly, m_isEnemy;
        int m_AP, m_HP, m_Tier;


    public: 
        clsCard(olc::vi2d init_Position);
        ~clsCard();
        void DrawSelf(olc::PixelGameEngine* pge);
    
    private:

};
