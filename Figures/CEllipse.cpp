#include "CEllipse.h"




CEllipse::CEllipse(Point P1, Point P2, double StartAng, double EndAng, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	TopLeftCorner = P1;
	BottomRightCorner = P2;
	StartAngle = StartAng;
	EndAngle = EndAng;
	//xLength = P2.x - p1.x;
	//yLength = p2.y - p1.y;

	startxLength = xLength;
	startyLength = yLength;
	
}


void CEllipse::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->DrawEllipse(TopLeftCorner, BottomRightCorner, FigGfxInfo, Selected);


}

bool CEllipse::isBelongTo(int x, int y) {
	Point center;
	center.x = 0.5 * (BottomRightCorner.x + TopLeftCorner.x);
	center.y = 0.5 * (BottomRightCorner.y + TopLeftCorner.y);
	float a = abs(BottomRightCorner.x - TopLeftCorner.x) / 2;
	float b = abs(BottomRightCorner.y - TopLeftCorner.y) / 2;
	float check = (pow(x - center.x, 2) / pow(a, 2)) + (pow(y - center.y, 2) / pow(b, 2));
	if (check <= 1)
		return true;
	return false;
}
