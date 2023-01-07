#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\GUI.h"
#include<fstream>
#include<string>

//Base class for all figures

class CFigure
{
protected:
	static int counter;
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	bool isHidden;
	GfxInfo FigGfxInfo;	//Figure graphis info
	string FigureName;
	/// Add more parameters if needed.

public:
	CFigure();

	CFigure(GfxInfo FigureGfxInfo);
	void SetSelected(bool );	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected

	bool CFigure::isShapeHiddin() const;
	void CFigure::HideShape();
	void CFigure::displayShape();

	virtual void DrawMe(GUI*) const  = 0 ;		//Draw the figure
	
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	color GetStrinColor(string s) const;
	string colorToString(color c);
	string getFigureName();
	string CFigure::GetFillClr();


	//virtual void Rotate() = 0;	//Rotate the figure
	virtual void Resize(GUI* pGUI, float size) = 0;	//Resize the figure
	//virtual void Move() = 0;		//Move the figure

	virtual bool isBelongTo(int x, int y) = 0;
	virtual void Save(ofstream& OutFile) = 0;

	virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar

};


#endif