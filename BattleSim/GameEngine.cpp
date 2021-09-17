#include "olcPixelGameEngine.h"

#include <cmath>
#include <string>

#include "Settings.h"
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
	InitSplashScreen(olc::BLACK);

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

	DrawSplashScreen(timeElapsed);	

	if (!flagMenuDisplay && flagHistDisplay) pGameBoard->DrawHistogram(dice_Sides, dice_RollNum);
	
	if (!flagMenuDisplay && flagBoardDisplay)
	{
		pGameBoard->DrawAllCards(LayerDraw);
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

void clsEngine::SelectScreenToDraw(clsSettings* settings)
{
	switch (settings->DrawWhat())
	{
	case clsSettings::Splash_Screen:
		break;
	case clsSettings::Menu_Screen:
		break;
	case clsSettings::Histogram_Screen:
		break;
	case clsSettings::CardSim_Screen:
		break;
	case clsSettings::Loading_Screen:
		break;
	default: //should return error
		break;
	}
}

void clsEngine::InitSplashScreen(olc::Pixel pixelColour_BG)
{
	clsUI_Element* SplashScreen_Title = new clsUI_Element(this);
	SplashScreen_Title->alignmentParameters.pct_PosY = 0.1f;
	SplashScreen_Title->AddString(SplashScreenText_Title);
	SplashScreen_Title->SetSize_Rel()

	mUI_SplashScreen.emplace_back()
	spr_olcLogo = new olc::Sprite("./olcPGE_Logo.png");
	SetDrawTarget(LayerBackground);
	Clear(pixelColour_BG);

	return;
}

void clsEngine::DrawSplashScreen(long double elapsedTime)
{

	if (!flagMenuDisplay) return; 

	SetDrawTarget(LayerBackground);
	//DrawRo

	float speedFactor{3.0f}; //speeds up the pulsating text, I would bet there's a better way to do this
	int textScaleFactor{3};

	if (flagMenuDisplay)
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
		UnloadSplashScreen();
	} 

	return;
}

void clsEngine::UnloadSplashScreen()
{
	flagMenuDisplay = false;
	Clear(olc::BLANK);
	delete spr_olcLogo;
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