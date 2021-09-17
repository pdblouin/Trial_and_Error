#pragma once

#include <vector>

#include "olcPixelGameEngine.h"
#include "UI_Element.h"
#include "Settings.h"
#include "Card.h"
#include "Board.h"

// Override base class with your custom functionality
class clsEngine : public olc::PixelGameEngine
{
public:
	clsEngine();
	~clsEngine();

	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;
	bool OnUserDestroy() override;

	void InitLayers();

	void SelectScreenToDraw(clsSettings* settings);

	void InitSplashScreen(olc::Pixel pixelColour_BG);
	void DrawSplashScreen(long double elapsedTime);
	void UnloadSplashScreen();

	float GetCentered_PosX(float itemPixelWidth);
	float GetCentered_PosX(std::string stringToCenter, float scaleFactor);
	int   GetCentered_PosX(int itemPixelWidth);
	int   GetCentered_PosX(std::string stringToCenter, int scaleFactor);
	

public:
	std::unique_ptr<clsBoard> pGameBoard{ nullptr };
	olc::Sprite* spr_olcLogo{ nullptr };

	enum layerIndex : uint8_t { LayerMain = 0, LayerDebug, LayerDraw, LayerBackground, LayerCount };

private:

	bool flagSplashScreen_Display{ true };
	const std::string SplashScreenText_Title{"PDB C++ Learning Project"};
	const std::string SplashScreenText_PrePNG{"Made using:"};
	const std::string SplashScreenText_Copyright{"Copyright 2018-2021 OneLoneCoder.com"};
	const std::string SplashScreenText_Enter{"Press [ENTER] to continue."};
	std::vector<clsUI_Element*> mUI_SplashScreen;

	bool flagHistDisplay{ true };
	bool flagBoardDisplay{ false };

	long double timeElapsed{ 0.0f };

	uint64_t framesRendered {0};

	uint8_t dice_Sides{6};
	uint64_t dice_RollNum{100};

};
