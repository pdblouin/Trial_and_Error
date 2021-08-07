#include "olcPixelGameEngine.h"
#include "GameEngine.h"


	clsEngine::clsEngine()
	{
		// Name your application
		sAppName = "Test_String";
		circlePos_X = ScreenWidth()/2;
		circlePos_Y = ScreenHeight()/2;
	}

    clsEngine::~clsEngine()
    {
        //Nothing
    }

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
	}

	bool clsEngine::OnUserCreate()
	{
		// Called once at the start, so create things here
		pGameBoard = new clsBoard;

		
		sprHeart = std::make_unique<olc::Sprite>("./heart.png");
		decHeart = std::make_unique<olc::Decal>(sprHeart.get());
		return true;
	}

	bool clsEngine::OnUserUpdate(float fElapsedTime)
	{
		// Called once per frame, draws random coloured pixels
		if (GetKey(olc::Key::X).bHeld) DrawDecal(UpdateInputCoords(), decHeart.get());
		pTest_card->DrawSelf(this);
		//FillCircle(UpdateCircleCoords(), 5);
		return true;
	}