#pragma once
#include "CFigure.h"

class CHexagon :
    public CFigure
{
    int SideLength;
    int Height;
    Point TopLeft;

public:
    CHexagon(Point, int, int, GfxInfo FigureGfxInfo);
    CHexagon();

    void DrawMe(GUI*) const;

    bool isBelongTo(int x, int y);
    void Resize(GUI* pGUI, float size);
     void Load(ifstream& Infile);	//Load the figure parameters to the file
     void Save(ofstream& OutFile);

    float CHexagon::AreaTriangle(float, float, float , float , float , float );
};

