
#include "UI_Element.h"

clsUI_Element::clsUI_Element(olc::PixelGameEngine* pointerToPixelGameEngine)
{
	pPGE = pointerToPixelGameEngine;
	alignmentParameters = Align_Param();
	mBtmRight_Bound = { static_cast<float>(pPGE->ScreenWidth()), static_cast<float>(pPGE->ScreenHeight()) };
}

clsUI_Element::clsUI_Element(olc::PixelGameEngine* pointerToPixelGameEngine, const std::string &filePathToPng)
{
	pPGE = pointerToPixelGameEngine;
	alignmentParameters = Align_Param();
	isDecal = true;
	mUI_SpritePtr = new olc::Sprite(filePathToPng);
	//mUI_SpritePtr = new olc::Sprite()

	mUI_DecalPtr = new olc::Decal(mUI_SpritePtr);
}

clsUI_Element::clsUI_Element(clsUI_Element* ptrToBaseObject)
{
	this->pPGE = ptrToBaseObject->pPGE;
	alignmentParameters = Align_Param();

	isRootObject = false;
	rootObjectPtr = ptrToBaseObject;
}

clsUI_Element::~clsUI_Element()
{
	if (mUI_SpritePtr != nullptr) { delete mUI_SpritePtr; }
	if (mUI_DecalPtr  != nullptr) { delete mUI_DecalPtr;  }
}

void clsUI_Element::AddString(const std::string& DisplayText)
{
	mDisplayString = DisplayText;
}

void clsUI_Element::DrawSelf()
{

}

void clsUI_Element::SetLayer(clsEngine::layerIndex drawLayer)
{
	mDrawToLayer = drawLayer;
}

void clsUI_Element::SetSize_Abs(int32_t size_X, int32_t size_Y)
{

}

void clsUI_Element::SetSize_Abs(float size_X, float size_Y)
{

}

void clsUI_Element::SetSize_Rel(float pct_X, float pct_Y)
{

}

void clsUI_Element::SetPos(olc::vf2d relativeTo_TopLeft, olc::vf2d relativeTo_BtmRight, Align_Param &alignParams)
{

}

float clsUI_Element::Width()
{
	return (mBtmRight_This.x - mTopLeft_This.x);
}

float clsUI_Element::Height()
{
	return (mBtmRight_This.y - mTopLeft_This.y);
}

bool clsUI_Element::is_Mouse_Overed()
{
	float mouseX = static_cast<float>(pPGE->GetMouseX());
	float mouseY = static_cast<float>(pPGE->GetMouseY());
	if ((mouseX < mBtmRight_This.x && mouseX > mTopLeft_This.x) && (mouseY < mBtmRight_This.y && mouseY > mTopLeft_This.y))
		return true;

	return false;
}

bool clsUI_Element::is_Mouse_Overed(const olc::vi2d &mousePos)
{
	float mouseX = static_cast<float>(mousePos.x);
	float mouseY = static_cast<float>(mousePos.y);
	if ((mouseX < mBtmRight_This.x && mouseX > mTopLeft_This.x) && (mouseY < mBtmRight_This.y && mouseY > mTopLeft_This.y))
		return true;

	return false;
}

Align_Param::Align_Param(Align_Param::eAlign_Type Type_alignX = ALIGN_CENTER, float Pct_alignX = 0.5f, 
						 Align_Param::eAlign_Type Type_alignY = ALIGN_CENTER, float Pct_alignY = 0.5f)
{
	align_X = Type_alignX;
	align_Y = Type_alignY;

	pct_PosX = Pct_alignX;
	pct_PosY = Pct_alignY;
}