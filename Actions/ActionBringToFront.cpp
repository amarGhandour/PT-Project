#include "ActionBringToFront.h"
#include "../ApplicationManager.h"
#include "../GUI/GUI.h"
#include <iostream>

ActionBringToFront::ActionBringToFront(ApplicationManager* pApp) :Action(pApp)
{

}
void ActionBringToFront::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	int res = pManager->bringToFront();
	if (res == 1) {
		pGUI->PrintMessage("Figure has been brought to front successfully");
	}
	else
	{
		pGUI->PrintMessage("No figure is selected");
	}
	pManager->unselectAll();
	pGUI->ClearDrawArea();
}