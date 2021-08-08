#pragma once

#include "olcPixelGameEngine.h"
#include "Card.h"
#include "Board.h"

// Override base class with your custom functionality
class clsEngine : public olc::PixelGameEngine
{
private:

	uint8_t backgroundLayer{ 0 };
	bool menuFlag_Display{ true };
	bool menuFlag_Clear{ true };

	float alphaValuePulsating{ 0.0f };

public:

	olc::Sprite* spr_olcLogo{ nullptr };

private:

public:
	clsEngine();
	~clsEngine();

	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;
	bool OnUserDestroy() override;

};
