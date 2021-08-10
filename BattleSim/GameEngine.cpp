#include "olcPixelGameEngine.h"

#include <cmath>
#include <string>

#include "GameEngine.h"
#include "Board.h"


clsEngine::clsEngine()
{
	// Name your application
	sAppName = "Test_String";

	//clsBoard* pGameBoard;
	//pGameBoard = new clsBoard;
};

clsEngine::~clsEngine()
{
    //delete pGameBoard;
};

bool clsEngine::OnUserCreate()
{
//Set up menu screen
	spr_olcLogo = new olc::Sprite("./olcPGE_Logo.png");
	Clear(olc::BLACK);
	DrawSprite({ (ScreenWidth() / 2 - (spr_olcLogo->width / 2)), (ScreenHeight() / 2 - spr_olcLogo->height / 2) }, spr_olcLogo);
	DrawString({ ScreenWidth() / 30 * 11, (ScreenHeight() / 3) }, "Made using:", olc::WHITE, 4);
	DrawString({ ScreenWidth() / 53 * (54/2 - 36/2), (ScreenHeight() / 3 * 2) }, "Copyright 2018\-2021 OneLoneCoder.com", olc::WHITE, 3);


	return true;
};

bool clsEngine::OnUserUpdate(float fElapsedTime)
{
	timeElapsed += fElapsedTime;
	DrawMenuScreen(flagMenuDisplay, timeElapsed, this);

	return true;	
};

bool clsEngine::OnUserDestroy()
{
	return true;
};

void DrawMenuScreen(bool& flagDisplay, long double elapsedTime, olc::PixelGameEngine* pge)
{

	bool debugMode{true};
	if (debugMode)
	{
		pge->DrawStringDecal({0.0f,0.0f}, std::to_string(elapsedTime), olc::WHITE, {3.0f, 3.0f});
		pge->DrawStringDecal({0.0f,30.0f}, std::to_string(128 + 128*(sinf(elapsedTime))), olc::WHITE, {3.0f, 3.0f});
	}

	if (flagDisplay)
	{
		pge->DrawStringDecal({ static_cast<float>(pge->ScreenWidth() / 4), static_cast<float>(pge->ScreenHeight() / 3 * 2.5f) }, 
			"Press [ENTER] to continue.", 
			olc::Pixel(255,255,255, static_cast<int>(128 + 128 * (sinf(elapsedTime)))),
			{ 3.0f, 3.0f });
	}

	if (pge->GetKey(olc::ENTER).bPressed && flagDisplay) { flagDisplay = false; pge->Clear(olc::WHITE); } 

	return;
}