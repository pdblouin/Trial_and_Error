#pragma once

#include "olcPixelGameEngine.h"
#include "GameEngine.h"

struct Align_Param
{
	enum eAlign_Type { ALIGN_LEFT = -1, ALIGN_CENTER = 0, ALIGN_RIGHT = 1 };

	Align_Param(Align_Param::eAlign_Type Type_alignX = ALIGN_CENTER, float Pct_alignX = 0.5f, Align_Param::eAlign_Type Type_alignY = ALIGN_CENTER, float Pct_alignY = 0.5f);

	eAlign_Type align_X;
	eAlign_Type align_Y;

	float pct_PosX;
	float pct_PosY;
};

class clsUI_Element
{
public:
	clsUI_Element(olc::PixelGameEngine* pointerToPixelGameEngine);
	clsUI_Element(olc::PixelGameEngine* pointerToPixelGameEngine, const std::string &filePathToPng);
	clsUI_Element(clsUI_Element* ptrToBaseObject);
	~clsUI_Element();

	void AddString(const std::string& DisplayText);

	void DrawSelf();
	void SetLayer(clsEngine::layerIndex drawLayer);

	std::vector<clsUI_Element*> subUI_Elements;

	Align_Param alignmentParameters;

	void SetSize_Abs(int32_t size_X, int32_t size_Y);
	void SetSize_Abs(float size_X, float size_Y);
	void SetSize_Rel(float pct_X, float pct_Y);

	void SetPos(olc::vf2d relativeTo_TopLeft, olc::vf2d relativeTo_BtmRight, Align_Param &alignParams);

	float Width();
	float Height();
	
	bool is_Mouse_Overed();
	bool is_Mouse_Overed(const olc::vi2d &mousePos);

	bool is_Selected();
	void Reset_Selection();
	static uint8_t Selection_Index;

private:

	olc::PixelGameEngine* pPGE{ nullptr };

	olc::Sprite* mUI_SpritePtr{ nullptr };
	olc::Decal*  mUI_DecalPtr { nullptr };
	
	bool isRootObject{ true };
	clsUI_Element* rootObjectPtr{ nullptr };

	bool isDecal{ false };

	std::string mDisplayString;

	uint8_t mDrawToLayer{ 0 };

	olc::vf2d mTopLeft_This{ 0.0f, 0.0f };
	olc::vf2d mBtmRight_This{ 0.0f, 0.0f };

	olc::vf2d mTopLeft_Bound{ 0.0f, 0.0f };
	olc::vf2d mBtmRight_Bound{ 0.0f, 0.0f };

};

