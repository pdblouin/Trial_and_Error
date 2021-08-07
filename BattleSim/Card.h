
#pragma once

class clsCard
{
    public: //Ideally public properties


    private: //Ideally private properties

        olc::vi2d m_Position;
        bool m_isFriendly, m_isEnemy;
        int m_AP, m_HP, m_Tier;


    public: //Public methods
        clsCard(olc::vi2d init_Position);
        ~clsCard();
        void DrawSelf(olc::PixelGameEngine* pge);
    private: //Private methods

};
