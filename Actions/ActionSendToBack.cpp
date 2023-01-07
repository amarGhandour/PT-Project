#include "ActionSendToBack.h"
#include "../ApplicationManager.h"
#include "../GUI/GUI.h"
#include <iostream>

ActionSendToBack::ActionSendToBack(ApplicationManager* pApp) :Action(pApp)
{

}
void ActionSendToBack::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	int res=pManager->sendToBack();

	//CFigure* fig = pManager->GetFigure();

	if (res == 1) {
		pGUI->PrintMessage("Figure has been sent to back successfully");
	}
	else
	{
		pGUI->PrintMessage("No figure is selected");
	}
	pManager->unselectAll();
	pGUI->ClearDrawArea();
}