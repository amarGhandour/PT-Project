#include "ActionSwitchToDrawMode.h"

#include"../ApplicationManager.h"
#include "../GUI/GUI.h"

ActionSwitchToDrawMode::ActionSwitchToDrawMode(ApplicationManager* pApp) :Action(pApp){}

void ActionSwitchToDrawMode::Execute() {

	GUI* pGUI = pManager->GetGUI();

	pGUI->CreateDrawToolBar();

	pGUI->PrintMessage("Welcome to draw mode ^_^");
}