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

CEllipse::CEllipse() {

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

void CEllipse::Resize(GUI* pGUI, float size)
{
	Point test1 = TopLeftCorner, test2 = BottomRightCorner;
	if (size == .5) size = -0.5;
	else if (size == .25) size = -(4.0 / 3);
	else if (size == 2) size = 1;
	else size = 3;

	// half radius (horizontal x && vertical y)
	float deltaX, deltaY;
	deltaX = 0.5 * (BottomRightCorner.x - TopLeftCorner.x);
	deltaY = 0.5 * (BottomRightCorner.y - TopLeftCorner.y);


	test1.x -= deltaX * size;
	test2.x += deltaX * size;
	test1.y -= deltaY * size;
	test2.y += deltaY * size;

	if (test1.y < UI.ToolBarHeight || test2.y > UI.height - UI.StatusBarHeight
		|| test2.x > UI.width || test1.x < 1)
	{
		pGUI->PrintMessage("Ellips size will be more than Drawing Area");
		Sleep(1000);
	}
	else if (((test2.x - test1.x) / 2) < 15 || ((test2.y - test1.y) / 2) < 10)
	{
		pGUI->PrintMessage("Ellips size will be very small");
		Sleep(1000);
	}
	else
	{
		TopLeftCorner = test1;
		BottomRightCorner = test2;
	}

}

void CEllipse::Load(ifstream& Infile)
{
	this->FigGfxInfo.BorderWdth = 3;

	string s;
	Infile >> this->ID >> this->TopLeftCorner.x >> this->TopLeftCorner.y
		>> this->BottomRightCorner.x >> this->BottomRightCorner.y;

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

void CEllipse::Save(ofstream& OutFile)      
{
	OutFile << "Ellipse\t" << ID << "\t" << this->TopLeftCorner.x << "\t" << this->TopLeftCorner.y << "\t"
		<< this->BottomRightCorner.x << "\t" << this->BottomRightCorner.y << "\t"
		<< this->colorToString(this->FigGfxInfo.DrawClr) << "\t";
	if (this->FigGfxInfo.isFilled)
		OutFile << this->colorToString(this->FigGfxInfo.FillClr) << "\n";
	else
		OutFile << "NON-FILLED\n";
	
}
