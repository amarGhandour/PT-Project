#pragma once
#include "../Figures/CFigure.h"
#include "Action.h"
class ActionPickType : public Action {
	CFigure* Fig;
	Point p;
	int shapes[4] = {};
	int no_shapes, rightAns, wrongAns, no_shapesEachCategory, randomShape;
	void score(int);

public:
	ActionPickType(ApplicationManager* pApp);
	void Execute();
};

