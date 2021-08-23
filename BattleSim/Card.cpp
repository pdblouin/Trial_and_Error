#include "olcPixelGameEngine.h"
#include "Card.h"

clsCard::clsCard(olc::PixelGameEngine* pPGE)
{
	m_Tier = std::rand() % 6; if (m_Tier = 0) m_Tier++;
	m_HP = std::rand() % 20; if (m_HP = 0) m_HP++;
	m_AP = std::rand() % 20; //It's OK if AP is zero
};

clsCard::~clsCard()
{
	
};


void clsCard::DrawSelf(olc::vf2d cardPosition)
{
	pPGE->SetDrawTarget(nullptr);
	pPGE->FillRectDecal(cardPosition, 
					    {static_cast<float>(pPGE->ScreenWidth()) * 0.1f, static_cast<float>(pPGE->ScreenHeight()) * 0.1f },
						olc::GREY);
	pPGE->SetDrawTarget(nullptr);
	pPGE->DrawStringDecal(cardPosition, std::to_string(m_AP) + " | " + std::to_string(m_HP), olc::YELLOW);
	return;
};
