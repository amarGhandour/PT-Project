#include "CHexagon.h"


CHexagon::CHexagon(Point point, int len, int height, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo) {
	TopLeft = point;
	SideLength = len;
	Height = height;
}

void CHexagon::DrawMe(GUI* pGUI) const {
	pGUI->DrawHexagon(TopLeft, SideLength, Height, FigGfxInfo, Selected);
}

bool CHexagon::isBelongTo(int x, int y)  {

	// if inside inner rectangle
	if (x >= TopLeft.x && x <= TopLeft.x + SideLength && y >= TopLeft.y && y <= TopLeft.y + Height)
		return true;
	
	float sideTrianglesArea = AreaTriangle(TopLeft.x, TopLeft.y, TopLeft.x, TopLeft.y + Height, TopLeft.x - 0.5 * SideLength, TopLeft.y + 0.5 * Height);
	
	// if inside left side triangle
	// left triangle >> (x,y), (x, y+h), (x-0.5l, y+0.5h)
	float Area1 = AreaTriangle(x, y, TopLeft.x, TopLeft.y + Height, TopLeft.x - 0.5 * SideLength, TopLeft.y + 0.5 * Height);
	float Area2 = AreaTriangle(TopLeft.x, TopLeft.y, x, y, TopLeft.x - 0.5 * SideLength, TopLeft.y + 0.5 * Height);
	float Area3 = AreaTriangle(TopLeft.x, TopLeft.y, TopLeft.x, TopLeft.y + Height, x, y);
	if (Area1 + Area2 + Area3 == sideTrianglesArea)
		return true;
	
	// if inside right side triangle
	// right triangle >> (x+l,y), (x+l, y+h), (x+1.5l, y+0.5h)
	Area1 = AreaTriangle(x, y, TopLeft.x + SideLength, TopLeft.y + Height, TopLeft.x + 1.5 * SideLength, TopLeft.y + 0.5 * Height);
	Area2 = AreaTriangle(TopLeft.x + SideLength, TopLeft.y, x, y, TopLeft.x + 1.5 * SideLength, TopLeft.y + 0.5 * Height);
	Area3 = AreaTriangle(TopLeft.x + SideLength, TopLeft.y, TopLeft.x + SideLength, TopLeft.y + Height, x, y);
	if (Area1 + Area2 + Area3 == sideTrianglesArea)
		return true;

	return false;
}


float CHexagon::AreaTriangle(float x1, float y1, float x2, float y2, float x3, float y3)
{
	return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) * 0.5);
}




