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
	pGameBoard = std::make_unique<clsBoard>(this);

	//Set up menu screen
	InitMenuScreen(olc::BLACK);

	

	/* Set up layers
	for(int i = LayerMain + 1; i < LayerCount; i++ )
	{
		CreateLayer();
		EnableLayer(i, true); //Enabling early, good or bad?
		SetDrawTarget(i);

		if (i % 2 == 1) Clear(olc::DARK_MAGENTA);
		else Clear(olc::DARK_GREEN);

		std::string LayerDescription = "This is layer: ";
		DrawString({ (ScreenWidth() / 30 * 11), (ScreenHeight() / 3) }, 
					 LayerDescription.append(std::to_string(i)), 
					 olc::WHITE, 4);
		
	}
	*/


	return true;
}

bool clsEngine::OnUserUpdate(float fElapsedTime)
{
	timeElapsed += fElapsedTime;

	DrawMenuScreen(flagMenuDisplay, timeElapsed);

	if (GetKey(olc::ENTER).bPressed)
	{
		EnableLayer(layerToDisplay, true);
		SetDrawTarget(layerToDisplay);
		Clear(olc::BLANK);
		layerToDisplay++;
		//if (layerToDisplay = LayerCount) { layerToDisplay = 0; }
		//EnableLayer(layerToDisplay,true);
	}

	pGameBoard;

	return true;	
}

bool clsEngine::OnUserDestroy()
{
	return true;
}


void clsEngine::InitMenuScreen(olc::Pixel pixelColour_BG)
{

	spr_olcLogo = new olc::Sprite("./olcPGE_Logo.png");
	SetDrawTarget(LayerMain);
	Clear(pixelColour_BG);
	DrawSprite({ (ScreenWidth() / 2 - (spr_olcLogo->width / 2)), (ScreenHeight() / 2 - spr_olcLogo->height / 2) }, spr_olcLogo);
	DrawString({ ScreenWidth() / 30 * 11, (ScreenHeight() / 3) }, "Made using:", olc::WHITE, 4);
	DrawString({ ScreenWidth() / 53 * (54/2 - 36/2), (ScreenHeight() / 3 * 2) }, "Copyright 2018-2021 OneLoneCoder.com", olc::WHITE, 3);

}

void clsEngine::DrawMenuScreen(bool& flagDisplay, long double elapsedTime)
{

	if (!flagDisplay) return; 

	SetDrawTarget(LayerMain);

	float speedFactor{ 3.0f}; //Need to define this outside this function eventually

	bool debugMode{true};
	if (debugMode)
	{
		DrawStringDecal({0.0f,0.0f}, std::to_string(elapsedTime), olc::WHITE, {3.0f, 3.0f});
		DrawStringDecal({0.0f,30.0f}, std::to_string(128 + 128*(sinf(elapsedTime))), olc::WHITE, {3.0f, 3.0f});
		speedFactor = 3.0f;
	}

	if (flagDisplay)
	{
		DrawStringDecal({ static_cast<float>(ScreenWidth() / 4), static_cast<float>(ScreenHeight() / 3 * 2.5f) }, 
			"Press [ENTER] to continue.", 
			olc::Pixel(255,255,255, static_cast<int>(128 + 128 * (sinf(elapsedTime * speedFactor)))),
			{ 3.0f, 3.0f });
	}

	if (GetKey(olc::ENTER).bPressed) { flagDisplay = false; Clear(olc::BLANK); } 

	return;
}