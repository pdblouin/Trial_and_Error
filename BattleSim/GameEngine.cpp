#include "olcPixelGameEngine.h"

#include <cmath>
#include <string>

#include "GameEngine.h"
#include "Board.h"


clsEngine::clsEngine()
{
	// Name your application
	sAppName = "Test_String";
}

clsEngine::~clsEngine()
{

}

bool clsEngine::OnUserCreate()
{

	//Set up menu screen
	InitMenuScreen(olc::BLACK);

	//Set up board state
	pGameBoard = std::make_unique<clsBoard>(this);
	pGameBoard->RunDiceRollSimulation(dice_Sides, dice_RollNum);


	for(int i = LayerFront + 1; i < LayerCount; i++ )
	{
		CreateLayer();
		EnableLayer(i, true);
		SetDrawTarget(i);
		Clear(olc::BLANK);		
	}

	pGameBoard->GenerateAllCards();

	return true;
}

bool clsEngine::OnUserUpdate(float fElapsedTime)
{
	timeElapsed += fElapsedTime;
	framesRendered++;

	DrawMenuScreen(flagMenuDisplay, timeElapsed);	

	if (!flagMenuDisplay && flagHistDisplay) pGameBoard->DrawHistogram(dice_Sides, dice_RollNum);
	if (!flagMenuDisplay && flagBoardDisplay) pGameBoard->DrawAllCards();

	return true;	
}

bool clsEngine::OnUserDestroy()
{
	return true;
}


void clsEngine::InitMenuScreen(olc::Pixel pixelColour_BG)
{

	spr_olcLogo = new olc::Sprite("./olcPGE_Logo.png");
	SetDrawTarget(LayerFront);
	Clear(pixelColour_BG);
	DrawSprite({ (ScreenWidth() / 2 - (spr_olcLogo->width / 2)), (ScreenHeight() / 2 - spr_olcLogo->height / 2) }, spr_olcLogo);
	DrawString({ ScreenWidth() / 30 * 11, (ScreenHeight() / 3) }, "Made using:", olc::WHITE, 4);
	DrawString({ ScreenWidth() / 53 * (54/2 - 36/2), (ScreenHeight() / 3 * 2) }, "Copyright 2018-2021 OneLoneCoder.com", olc::WHITE, 3);
	
	return;
}

void clsEngine::DrawMenuScreen(bool& flagDisplay, long double elapsedTime)
{

	if (!flagDisplay) return; 

	SetDrawTarget(LayerFront);

	float speedFactor{ 3.0f}; //speeds up the pulsating text, I would bet there's a better way to do this

	if (flagDisplay)
	{
		DrawStringDecal({ static_cast<float>(ScreenWidth() / 4), static_cast<float>(ScreenHeight() / 3 * 2.5f) }, 
			"Press [ENTER] to continue.", 
			olc::Pixel(255,255,255, static_cast<int>(128 + 128 * (sinf(elapsedTime * speedFactor)))),
			{ 3.0f, 3.0f });
	}

	if (GetKey(olc::ENTER).bPressed) { flagDisplay = false; Clear(olc::BLACK); } 

	return;
}