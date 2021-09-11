#pragma once

#include "olcPixelGameEngine.h"
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

	void InitMenuScreen(olc::Pixel pixelColour_BG);
	void DrawMenuScreen(bool& flagDisplay, long double elapsedTime);

	float GetCentered_PosX(float itemPixelWidth);
	float GetCentered_PosX(std::string stringToCenter, float scaleFactor);
	int   GetCentered_PosX(int itemPixelWidth);
	int   GetCentered_PosX(std::string stringToCenter, int scaleFactor);
	

public:
	std::unique_ptr<clsBoard> pGameBoard{ nullptr };
	olc::Sprite* spr_olcLogo{ nullptr };

private:

	enum layerIndex : uint8_t { LayerMain = 0, LayerDebug, LayerDraw, LayerBackground, LayerCount };

	bool flagMenuDisplay{ true };
	const std::string menuText_Title{"PDB C++ Learning Project"};
	const std::string menuText_PrePNG{"Made using:"};
	const std::string menuText_Copyright{"Copyright 2018-2021 OneLoneCoder.com"};
	const std::string menuText_Enter{"Press [ENTER] to continue."};

	bool flagHistDisplay{ false };
	bool flagBoardDisplay{ true };

	long double timeElapsed{ 0.0f };

	uint64_t framesRendered {0};

	uint8_t dice_Sides{6};
	uint64_t dice_RollNum{100};

};