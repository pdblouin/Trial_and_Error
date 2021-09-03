#include "olcPixelGameEngine.h"
#include "Card.h"

clsCard::clsCard(olc::PixelGameEngine* pointerToPixelGameEngine)
{
	//Drawing stuff
	pPGE = pointerToPixelGameEngine;
	pCard_Sprite = new olc::Sprite(CardPath);
	pCard_Decal = new olc::Decal(pCard_Sprite);
	
	scaleFactor = GetScaleFactor();

	//Card properties
	m_Tier = std::rand() % 6; if (m_Tier == 0) m_Tier++;
	m_HP = std::rand() % 20; if (m_HP == 0) m_HP++;
	m_AP = std::rand() % 20; //It's OK if AP is zero

};

clsCard::~clsCard()
{
	delete pCard_Sprite;
	delete pCard_Decal;
};


void clsCard::DrawSelf(olc::vf2d cardPosition)
{
	pPGE->SetDrawTarget(nullptr);
	pPGE->DrawDecal(cardPosition, pCard_Decal, { scaleFactor, scaleFactor });	
	pPGE->SetDrawTarget(nullptr);
	pPGE->DrawStringDecal(cardPosition * 1.01f, std::to_string(m_AP) + "/" + std::to_string(m_HP), olc::YELLOW, {1.55f, 1.55f});
	return;
};

float clsCard::GetScaleFactor()
{
	float tempFloat{ 1.0f };
	if (pCard_Sprite == nullptr || pPGE == nullptr) return tempFloat;
	tempFloat = (static_cast<float>(pPGE->ScreenHeight()) / 4.0f) / static_cast<float>(pCard_Sprite->height);
	return tempFloat;
};

float clsCard::GetWidth()
{
	return static_cast<float>(pCard_Sprite->width) * scaleFactor;
};