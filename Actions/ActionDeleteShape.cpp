#include "ActionDeleteShape.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"

ActionDeleteShape::ActionDeleteShape(ApplicationManager* pApp) : Action(pApp){}

//Excuting Action
void ActionDeleteShape::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	
	
	pManager->deleteShapes();
	pGUI->ClearDrawArea();

}