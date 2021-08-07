#pragma once

#include "olcPixelGameEngine.h"
#include "Card.h"
#include "Board.h"

// Override base class with your custom functionality
class clsEngine : public olc::PixelGameEngine
{
private:

	int circlePos_X, circlePos_Y;

	std::unique_ptr<olc::Sprite> sprHeart;
	std::unique_ptr<olc::Decal> decHeart;
	clsCard* pTest_card;
	clsBoard* pGameBoard;

public:
	clsEngine();
    ~clsEngine();

	olc::vi2d UpdateInputCoords();

public:

	bool OnUserCreate() override;

	bool OnUserUpdate(float fElapsedTime) override;

	//bool OnUserDestroy() override;

};
