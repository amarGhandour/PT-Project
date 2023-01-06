#include "CFigure.h"

class CEllipse :
    public CFigure
{
private:
	Point TopLeftCorner;
	Point BottomRightCorner;
	double  StartAngle;
	double  EndAngle;
	int xLength, yLength;
	int startxLength, startyLength;
public:
	CEllipse(Point, Point, double, double, GfxInfo FigureGfxInfo);
	CEllipse();

	virtual void DrawMe(GUI* pOut) const;

	bool isBelongTo(int x, int y);
	void Resize(GUI* pGUI, float size);
	void Load(ifstream& Infile);	
	void Save(ofstream& OutFile);


};

