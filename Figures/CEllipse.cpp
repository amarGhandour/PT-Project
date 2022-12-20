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

	double rw = abs(TopLeftCorner.x - BottomRightCorner.x);
	double rh = abs(TopLeftCorner.y - BottomRightCorner.y);

	double a = rw / sqrt(2);
	double b = rh / sqrt(2);

	double h = BottomRightCorner.x -  (rw / 2);
	double k = BottomRightCorner.y - (rh / 2);

	int res = (pow((x - h), 2) / pow(a, 2)) + (pow((y - k), 2) / pow(b, 2));
	

	//if ((TopLeftCorner.x <= x && BottomRightCorner.x >= x && (TopLeftCorner.y <= y && BottomRightCorner.y >= y))) {
	//	return true;
	//}

	return res <= 1;
}
