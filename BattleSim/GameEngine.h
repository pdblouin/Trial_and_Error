#pragma once

#include "olcPixelGameEngine.h"
#include "Card.h"
#include "Board.h"

// Override base class with your custom functionality
class clsEngine : public olc::PixelGameEngine
{
private:

	enum layerIndex : uint8_t { LayerFront = 0, LayerMain, LayerBackground, LayerCount };

	bool flagMenuDisplay{ true };

	long double timeElapsed{ 0.0f };

	int layerToDisplay {0};

	long long framesRendered {0};

	int dice_Sides{6};
	int dice_RollNum{100};

public:
	std::unique_ptr<clsBoard> pGameBoard{ nullptr };

	olc::Sprite* spr_olcLogo{ nullptr };

private:

public:
	clsEngine();
	~clsEngine();

	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;
	bool OnUserDestroy() override;

	void DrawMenuScreen(bool& flagDisplay, long double elapsedTime);
	void InitMenuScreen(olc::Pixel pixelColour_BG);


};