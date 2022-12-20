#include "ActionAddCircle.h"

#include "..\GUI\GUI.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CCircle.h"

ActionAddCircle::ActionAddCircle(ApplicationManager *pApp):Action(pApp) {}

void ActionAddCircle::Execute() {

	Point p1, p2;

	GUI* pGUI = pManager->GetGUI();

	GfxInfo SqrGfxInfo;
	SqrGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SqrGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	SqrGfxInfo.FillClr = pGUI->getCrntFillColor();
	SqrGfxInfo.BorderWdth = pGUI->getCrntPenWidth();


	pGUI->PrintMessage("New Circle: Enter center point.");
	pGUI->GetPointClicked(p1.x, p1.y);

	pGUI->PrintMessage("New Circle: Enter radius point.");
	pGUI->GetPointClicked(p2.x, p2.y);

	pGUI->ClearStatusBar();


	int radius = (int) sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));

	CCircle* circle = new CCircle(p1, radius, SqrGfxInfo);


	pManager->AddFigure(circle);

}