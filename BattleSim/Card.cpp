#include "olcPixelGameEngine.h"
#include "Card.h"

clsCard::clsCard(olc::PixelGameEngine* pPGE, bool setRandomStats = true)
{
	if (setRandomStats)
	{
		m_Tier = std::rand() % 6; if (m_Tier = 0) m_Tier++;
		m_HP = std::rand() % 20; if (m_HP = 0) m_HP++;
		m_AP = std::rand() % 20; //It's OK if AP is zero
	}
	else
	{
	m_AP = 0;
	m_HP = 0;
	m_Tier = 0;
	}
};

clsCard::~clsCard()
{
	
};


void clsCard::DrawSelf()
{
	return;
};
