#pragma once

#include "olcPixelGameEngine.h"
#include "Card.h"
#include "Board.h"

// Override base class with your custom functionality
class clsEngine : public olc::PixelGameEngine
{
private:

	bool flagMenuDisplay{ true };

	long double timeElapsed{ 0.0f };

public:
	clsBoard* pGameBoard{ nullptr };

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