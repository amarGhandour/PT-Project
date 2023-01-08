#include "CCircle.h"


CCircle::CCircle(Point center, int _radius, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo) {
	this->center = center;
	this->radius = _radius;
	FigureName = "CIRCLE";

}


CCircle::CCircle() {
	FigureName = "CIRCLE";

}

void CCircle::DrawMe(GUI* pGUI) const {
	pGUI->DrawCircle(center, radius, FigGfxInfo, Selected);

}

bool CCircle::isBelongTo(int x, int y) {
	//(x - center_x)² + (y - center_y)² < radius².
	double dx = pow(x - center.x, 2);
	double dy = pow(y - center.y, 2);

	if (dx + dy < radius * radius)
		return true;

	return false;
}

void CCircle::Resize(GUI* pGUI, float size)
{

	float radius_test = radius * size;

	if ((center.y + radius_test) > UI.height - UI.StatusBarHeight
		|| (center.x + radius_test * 1.5) > UI.width
		|| (center.x - radius * 0.5) < 1)
	{
		pGUI->PrintMessage("Circle size will be more than Drawing Area");
		Sleep(1000);
	}
	else if (radius_test < 20)
	{
		pGUI->PrintMessage("Circle size will be very small");
		Sleep(1000);
	}
	else
	{
		radius = radius_test;
	}

}

void CCircle::Load(ifstream& Infile)
{
	this->FigGfxInfo.BorderWdth = 3;

	string s;
	Infile >> this->ID >> this->center.x >> this->center.y
		>> this->radius;

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

void CCircle::Save(ofstream& OutFile)
{
	OutFile << "Circle\t" << ID << "\t" << this->center.x << "\t" << this->center.y << "\t"
		<< this->radius << "\t"
		<< this->colorToString(this->FigGfxInfo.DrawClr) << "\t";
	if (this->FigGfxInfo.isFilled)
		OutFile << this->colorToString(this->FigGfxInfo.FillClr) << "\n";
	else
		OutFile << "NON-FILLED\n";

}
