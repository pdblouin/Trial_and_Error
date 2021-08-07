#include "olcPixelGameEngine.h"
#include "Card.h"

//Constructor
clsCard::clsCard(olc::vi2d init_Position)
	: m_Position(init_Position)
{

}

//Destructor
clsCard::~clsCard(){};


void clsCard::DrawSelf(olc::PixelGameEngine* pge)
{
	pge->FillRect(m_Position, { 100,300 });
	return;
}
