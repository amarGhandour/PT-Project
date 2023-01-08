#include "ActionAddEllipse.h"

#include "..\Figures\CEllipse.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"

ActionAddEllipse::ActionAddEllipse(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionAddEllipse::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();


	GfxInfo SqrGfxInfo;
	SqrGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SqrGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	SqrGfxInfo.FillClr = pGUI->getCrntFillColor();
	SqrGfxInfo.BorderWdth = pGUI->getCrntPenWidth();


	//Step 1 - Read Square data from the user

	pGUI->PrintMessage("New Ellipse: Click at first point");
	//Read 1st point and store in point P1
	pGUI->GetPointClicked(P1.x, P1.y);

	pGUI->PrintMessage("New Ellipse: Click at second point");
	//Read 2nd point and store in point P2
	pGUI->GetPointClicked(P2.x, P2.y);

	pGUI->ClearStatusBar();
	if (P1.y < UI.ToolBarHeight || P2.y < UI.ToolBarHeight
		|| P1.y>UI.height - UI.StatusBarHeight || P2.y>UI.height - UI.StatusBarHeight)
	{
		pGUI->PrintMessage("draw inside drawing area");
	}
	else
	{

		double StartAngle = 0;
		double EndAngle = 360;
		CEllipse* R = new CEllipse(P1, P2, StartAngle, EndAngle, SqrGfxInfo);

		pManager->AddFigure(R);
	}
}
