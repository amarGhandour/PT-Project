#ifndef GUI_H
#define GUI_H

#include "..\DEFS.h"
#include "UI_Info.h" 
#include "..\CMUgraphicsLib\CMUgraphics.h"


//This class is responsible for Grphical User Interface handling
//All user input and program outputs MUST be done through this class
//No other class is allowed to perform direct i/o
class GUI	
{
public:	
	window* pWind;	//Pointer to the Graphics Window
public:
	GUI();	
	~GUI();	
	window* CreateWind(int, int, int , int) const; //creates the application window

	/////////// Input Functoinality  /////////////////
	void GetPointClicked(int &x, int &y) const;//Get coordinate where user clicks
	string GetSrting() const ;	 //Returns a string entered by the user
	ActionType MapInputToActionType() const; //Read the user click and map to an action


	/////////// Output Functoinality  ////////////////
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar
	void CreateSizeBar() const;
	void CreateToolBar() const;
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area
	
	// -- Figures Drawing functions
	void DrawSquare(Point P1, int length, GfxInfo RectGfxInfo, bool selected=false) const;  //Draw a Square
	void GUI::DrawEllipse(Point P1, Point p2, GfxInfo CircGfxInfo, bool selected = false) const;
	void DrawCircle(Point P1, int radius, GfxInfo CircGfxInfo, bool selected = false) const;
	void DrawHexagon(Point P1, int length, int height, GfxInfo HexGfxInfo, bool selected = false) const;

	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width
	bool getIsFilled() const;
	void setCrntDrawColor(color c) const;
	void setCrntFillColor(color c) const;
	void setCrntBKGrandColor(color c) const;

};


#endif