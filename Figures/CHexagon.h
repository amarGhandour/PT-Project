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

    void DrawMe(GUI*) const;

    bool isBelongTo(int x, int y);

    float CHexagon::AreaTriangle(float, float, float , float , float , float );
};

