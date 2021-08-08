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

	if (menuFlag_Display)
	{
		float throwawayInt;
		DrawStringDecal({ static_cast<float>(ScreenWidth() / 4), static_cast<float>(ScreenHeight() / 3 * 2.5f) }, 
			"Press [ENTER] to continue.", 
			olc::Pixel(255,255,255, static_cast<int>(255 * abs(sinf(alphaValuePulsating)))),
			{ 3.0f, 3.0f });

		alphaValuePulsating = alphaValuePulsating + fElapsedTime;
	}

	if (GetKey(olc::ENTER).bPressed) { menuFlag_Display = false; }
	if (!menuFlag_Display && menuFlag_Clear) { Clear(olc::WHITE); menuFlag_Clear = false; } //Only happens once, then flag is flipped

	return true;	
};

bool clsEngine::OnUserDestroy()
{
	return true;
};