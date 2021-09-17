#pragma once


class clsSettings
{
public:
	enum ScreenDrawIndex : uint8_t { Splash_Screen = 0, Menu_Screen, Histogram_Screen, CardSim_Screen, Loading_Screen, Screen_Count };

	clsSettings();
	~clsSettings();

	ScreenDrawIndex DrawWhat();

	const int test_int{ 3 };

	

private:

	ScreenDrawIndex screenToDraw = Splash_Screen;

};