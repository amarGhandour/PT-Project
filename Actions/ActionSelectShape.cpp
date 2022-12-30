#include "ActionSelectShape.h"
#include "../GUI/GUI.h"
#include "../ApplicationManager.h"

ActionSelectShape::ActionSelectShape(ApplicationManager* pApp):Action(pApp){}

void ActionSelectShape::Execute() {
	Point point;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();


	//Step 1 - Read Square data from the user

	//pGUI->PrintMessage("Select shape: Click at any shape");
	//Read 1st point and store in point P1
	pGUI->GetPointClicked(point.x, point.y);


	pGUI->ClearStatusBar();

	CFigure* fig = pManager->GetFigure(point.x, point.y);

	if (fig) {
		fig->SetSelected(!fig->IsSelected());
	}

}