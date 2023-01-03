
#include "CFigure.h"


class CCircle :
    public CFigure
{
    int radius;
    Point center;

public:
     CCircle(Point, int, GfxInfo FigureGfxInfo);

     void DrawMe(GUI*) const;

     bool isBelongTo(int x, int y);
     void Resize(GUI* pGUI, float size);
     void Save(ofstream& OutFile);

     void Load(ifstream& Infile);	//Load the figure parameters to the file

};

