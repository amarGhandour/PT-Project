#include "CHexagon.h"




CHexagon::CHexagon() {

};

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

void CHexagon::Resize(GUI* pGUI, float size)
{

	float length_test = SideLength * size;
	float height_test = Height * size;
	if ((TopLeft.y + height_test) > UI.height - UI.StatusBarHeight
		|| (TopLeft.x + length_test * 1.5) > UI.width
		|| (TopLeft.x - length_test * 0.5) < 1)
	{
		pGUI->PrintMessage("Hexagon size will be more than Drawing Area");
		Sleep(1000);
	}
	else if (length_test < 20 || height_test < 20)
	{
		pGUI->PrintMessage("Hexagon size will be very small");
		Sleep(1000);
	}
	else
	{
		SideLength = length_test;
		SideLength = height_test;
		//PrintInfo(pGUI);
	}



}

void CHexagon::Load(ifstream& Infile)
{
	this->FigGfxInfo.BorderWdth = 3;

	string s;
	Infile >> this->ID >> this->TopLeft.x >> this->TopLeft.y
		>> this->SideLength >> this->Height;

	int r, g, b;
	Infile >> r >> g >> b;
	this->FigGfxInfo.DrawClr = color(r, g, b);

	Infile >> s;
	if (!(s == "NON-FILLED")) {
		r = (int)s[0];

		Infile >> g >> b;

		this->FigGfxInfo.FillClr = color(r, g, b);
		this->FigGfxInfo.isFilled = true;
	}
	else
		this->FigGfxInfo.isFilled = false;


}

void CHexagon::Save(ofstream& OutFile)
{
	OutFile << "Hexagon\t" << this->ID << "\t" << this->TopLeft.x << "\t" << this->TopLeft.y << "\t"
		<< this->SideLength << "\t" << this->Height << "\t"
		<< this->colorToString(this->FigGfxInfo.DrawClr) << "\t";
	if (this->FigGfxInfo.isFilled)
		OutFile << this->colorToString(this->FigGfxInfo.FillClr) << "\n";
	else
		OutFile << "NON-FILLED\n";
}





