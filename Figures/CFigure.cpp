#include "CFigure.h"
#include <sstream>
#include <iostream>

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	ID = ++CFigure::counter;
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	isHidden = false;
}

CFigure::CFigure()
{
	++CFigure::counter;
	Selected = false;
	isHidden = false;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

string CFigure::getFigureName() {
	return FigureName;
}

string CFigure::colorToString(color c)
{
	std::ostringstream os;
	os << int(c.ucRed) << "\t";
	os << int(c.ucGreen) << "\t";
	os << int(c.ucBlue);

	std::string s = os.str();

	return s;
}
color CFigure::GetStrinColor(string s) const
{
	if (s == "BLUE")
		return BLUE;
	if (s == "RED")
		return RED;
	if (s == "YELLOW")
		return YELLOW;
	if (s == "GREEN")
		return GREEN;
	if (s == "LIGHTGOLDENRODYELLOW")
		return LIGHTGOLDENRODYELLOW;
	if (s == "MAGENTA")
		return MAGENTA;
	if (s == "TURQUOISE")
		return TURQUOISE;
	if (s == "PINK")
		return PINK;
	if (s == "MAROON")
		return MAROON;
	if (s == "PURPLE")
		return PURPLE;
	return BLACK;
}

bool CFigure::isShapeHiddin() const {
	return isHidden;
}
void CFigure::HideShape() {
	isHidden = true;
}
void CFigure::displayShape() {
	isHidden = false;
}

