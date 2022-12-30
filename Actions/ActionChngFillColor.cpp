#include "ActionChngFillColor.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"

ActionChngFillColor::ActionChngFillColor(ApplicationManager* pApp):Action(pApp)
{}
void ActionChngFillColor::Execute()

{
	Point P1;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();

	pGUI->PrintMessage("Change fill color: pick on any color");
	//Read point and store in point P1
	pGUI->GetPointClicked(P1.x, P1.y);

	pGUI->ClearStatusBar();
	color Fclr = pGUI->pWind->GetColor(P1.x, P1.y);

	pManager->changeFillColor(Fclr);

	pGUI->ClearDrawArea();


}
