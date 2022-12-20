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

	virtual void DrawMe(GUI* pOut) const;

	bool isBelongTo(int x, int y);

};

