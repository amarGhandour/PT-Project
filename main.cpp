#include "ApplicationManager.h"
#include "GUI\GUI.h"
#include "Actions\ActionPickColor.h"


int CFigure::counter = 0;
string ActionPickColor::lastColor = "";

int main()
{
	ApplicationManager AppManager;
	AppManager.Run();		
	return 0;
}

