#include "ActionChngBGCol.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"

ActionChngBGCol::ActionChngBGCol(ApplicationManager* pApp) :Action(pApp)
{}
//Execute the action
void ActionChngBGCol::Execute()
{
	Point P1;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();


	//Step 1 - Read color data from the user

	pGUI->PrintMessage("New BG color: Click at the color you want (inside this window)");

	//Read 1st point and store in point P1
	pGUI->GetPointClicked(P1.x, P1.y);

	pGUI->ClearStatusBar();

	//Step 2 - prepare color data
	//User has entered one point P1
	//2.1- Identify the required color of the BG
	color bg=pGUI->pWind->GetColor(P1.x, P1.y);
	UI.BkGrndColor=bg;
	pGUI->ClearDrawArea();




}
