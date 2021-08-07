#include "olcPixelGameEngine.h"
#include "GameEngine.h"
#include "Board.h"


	clsEngine::clsEngine()
	{
		// Name your application
		sAppName = "Test_String";

		//clsBoard* pGameBoard;
		//pGameBoard = new clsBoard;

		int circlePos_X = 0;
		int circlePos_Y = 0;
	};

    clsEngine::~clsEngine()
    {
        //delete pGameBoard;
    };

	olc::vi2d clsEngine::UpdateInputCoords()
	{
		int posX = ScreenWidth();
		int posY = ScreenHeight();

		int modX = posX / 50;
		int modY = posY / 50;

		circlePos_X = (std::rand() % 2 == 0) ? circlePos_X + std::rand() % modX : circlePos_X - std::rand() % modX;
		circlePos_Y = (std::rand() % 2 == 0) ? circlePos_Y + std::rand() % modY : circlePos_Y - std::rand() % modY;

		if (circlePos_X > posX) circlePos_X = posX;
		if (circlePos_Y > posY) circlePos_Y = posY;

		if (circlePos_X < 0) circlePos_X = 0;
		if (circlePos_Y < 0) circlePos_Y = 0;

		return { circlePos_X, circlePos_Y };
	};

	bool clsEngine::OnUserCreate()
	{
		return true;
	};

	bool clsEngine::OnUserUpdate(float fElapsedTime)
	{
		//Clear(olc::VERY_DARK_BLUE);

		//DrawString(UpdateInputCoords(),"Hello", olc::CYAN, 10);
		
		return true;
	};