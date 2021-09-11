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
	InitLayers();
	InitMenuScreen(olc::BLACK);

	//Set up board state
	pGameBoard = std::make_unique<clsBoard>(this);
	pGameBoard->RunDiceRollSimulation(dice_Sides, dice_RollNum);

	pGameBoard->GenerateAllCards();

	return true;
}

bool clsEngine::OnUserUpdate(float fElapsedTime)
{
	timeElapsed += fElapsedTime;
	framesRendered++;

	DrawMenuScreen(flagMenuDisplay, timeElapsed);	

	if (!flagMenuDisplay && flagHistDisplay) pGameBoard->DrawHistogram(dice_Sides, dice_RollNum);
	
	if (!flagMenuDisplay && flagBoardDisplay)
	{
		SetDrawTarget(LayerDraw);
		DrawStringDecal({ 0.0f, ((float)ScreenHeight() / 2.0f) }, "Testing, this is in front.", olc::WHITE, { 5.0f, 5.0f });
		
		pGameBoard->DrawAllCards(LayerDraw);
		
		SetDrawTarget(LayerDraw);
		DrawStringDecal({ 0.0f, ((float)ScreenHeight() / 3.0f) }, "Testing, this is in back.", olc::WHITE, { 5.0f, 5.0f });
	}

	if (GetKey(olc::ENTER).bPressed) 
	{
		pGameBoard->DeleteAllCards();
		pGameBoard->GenerateAllCards(); 
		SetDrawTarget(nullptr); 
		Clear(olc::BLANK);
	}

	return true;	
}

bool clsEngine::OnUserDestroy()
{
	return true;
}

void clsEngine::InitLayers()
{
	SetDrawTarget(nullptr);
	Clear(olc::BLANK);

	for(uint8_t i = LayerMain + 1; i < LayerCount; i++ )
	{
		CreateLayer();
		EnableLayer(i, true);
		SetDrawTarget(i);
		Clear(olc::BLANK);		
	}
}

void clsEngine::InitMenuScreen(olc::Pixel pixelColour_BG)
{

	spr_olcLogo = new olc::Sprite("./olcPGE_Logo.png");
	SetDrawTarget(LayerBackground);
	Clear(pixelColour_BG);
	
	return;
}

void clsEngine::DrawMenuScreen(bool& flagDisplay, long double elapsedTime)
{

	if (!flagDisplay) return; 

	SetDrawTarget(LayerBackground);

	float speedFactor{3.0f}; //speeds up the pulsating text, I would bet there's a better way to do this
	int textScaleFactor{3};

	if (flagDisplay)
	{
		DrawSprite({ (ScreenWidth() / 2 - (spr_olcLogo->width / 2)), (ScreenHeight() / 2 - spr_olcLogo->height / 2) }, spr_olcLogo);
	
		DrawString({GetCentered_PosX(menuText_Title, textScaleFactor), ScreenHeight() / 6}, menuText_Title, olc::WHITE, textScaleFactor);
		DrawString({GetCentered_PosX(menuText_PrePNG, textScaleFactor), ScreenHeight() / 3}, menuText_PrePNG, olc::WHITE, textScaleFactor);
		DrawString({GetCentered_PosX(menuText_Copyright, textScaleFactor), (ScreenHeight() / 3) * 2}, menuText_Copyright, olc::WHITE, textScaleFactor);
		
		DrawStringDecal({ GetCentered_PosX(menuText_Enter, static_cast<float>(textScaleFactor)), static_cast<float>(ScreenHeight() / 3) * 2.5f }, 
			menuText_Enter, 
			olc::Pixel(255,255,255, static_cast<int>(128 + 128 * (sinf(elapsedTime * speedFactor)))),
			{ static_cast<float>(textScaleFactor), static_cast<float>(textScaleFactor) });
	}

	if (GetKey(olc::ENTER).bPressed)
	{ 
		flagDisplay = false; 
		Clear(olc::BLANK);
		delete spr_olcLogo;
	} 

	return;
}

float clsEngine::GetCentered_PosX(float itemPixelWidth)
{
	return static_cast<float>(ScreenWidth())/2.0f - itemPixelWidth/2.0f;
}

float clsEngine::GetCentered_PosX(std::string stringToCenter, float scaleFactor)
{
	return GetCentered_PosX((static_cast<float>(GetTextSize(stringToCenter).x) * scaleFactor));
}

int clsEngine::GetCentered_PosX(int itemPixelWidth)
{
	return ScreenWidth()/2 - itemPixelWidth/2;
}

int clsEngine::GetCentered_PosX(std::string stringToCenter, int scaleFactor)
{
	return GetCentered_PosX(((GetTextSize(stringToCenter).x) * scaleFactor));
}