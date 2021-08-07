#pragma once

#include "olcPixelGameEngine.h"
#include "Card.h"
#include "Board.h"

// Override base class with your custom functionality
class clsEngine : public olc::PixelGameEngine
{
private:

	int circlePos_X, circlePos_Y;

public:
	clsEngine();
    ~clsEngine();

	olc::vi2d UpdateInputCoords();

public:

	bool OnUserCreate() override;

	bool OnUserUpdate(float fElapsedTime) override;

	//bool OnUserDestroy() override;

};
