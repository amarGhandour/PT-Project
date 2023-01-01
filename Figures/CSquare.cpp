#include "CSquare.h"

CSquare::CSquare(Point P1, int len, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	TopLeftCorner = P1;
	length = len;
}
	

void CSquare::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->DrawSquare(TopLeftCorner, length, FigGfxInfo, Selected);
}

bool CSquare::isBelongTo(int x, int y)  {

	if (x >= TopLeftCorner.x && x <= TopLeftCorner.x + length && y >= TopLeftCorner.y && y <= TopLeftCorner.y + length)
		return true;

	return false;
}

void CSquare::Resize(GUI* pGUI, float size)
{
	float length_test = length;
	Point test1 = TopLeftCorner;
	Point test2;
	test2.x = test1.x + length;
	test2.y = test1.y + length;
	length_test *= size;
	test2.x = test1.x + length_test;
	test2.y = test1.y + length_test;

	if (test1.y < UI.ToolBarHeight || test2.y > UI.height - UI.StatusBarHeight
		|| test2.x > UI.width || test1.x < 1)
	{
		pGUI->PrintMessage("Square size will be more than Drawing Area");
		Sleep(1000);
	}
	else if (length_test < 20)
	{
		pGUI->PrintMessage("Square size will be very small");
		Sleep(1000);
	}
	else
	{
		TopLeftCorner = test1;
		length = length_test;
		//PrintInfo(pGUI);
	}


}