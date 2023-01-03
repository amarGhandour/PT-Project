#ifndef CSQUARE_H
#define CSQUARE_H

#include "CFigure.h"

class CSquare : public CFigure
{
private:
	Point TopLeftCorner;	
	int length;
public:
	CSquare();
	CSquare(Point , int, GfxInfo FigureGfxInfo );
	virtual void DrawMe(GUI* pOut) const;
	
	bool isBelongTo(int x, int y);
	void Resize(GUI* pGUI, float size);
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);

};

#endif