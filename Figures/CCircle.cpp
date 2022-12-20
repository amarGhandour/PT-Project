#include "CCircle.h"


CCircle::CCircle(Point center, int _radius, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo) {
	this->center = center;
	this->radius = _radius;
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