#include "ApplicationManager.h"
#include "Actions\ActionAddSquare.h"
#include "Actions\ActionAddCircle.h"
#include "Actions\ActionAddHexagon.h"
#include "Actions\ActionAddEllipse.h"
#include "Actions\ActionDeleteShape.h"
#include "Actions\ActionSelectShape.h"
#include "Actions\ActionChngBGCol.h"
#include "Actions\ActionChngDrawCol.h"
#include "Actions\ActionChngFillColor.h"
#include "Actions\Resize.h"


//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pGUI = new GUI;	
	
	FigCount = 0;
		
	//Create an array of figure pointers and set them to NULL		
	//for(int i=0; i<MaxFigCount; i++)
		//FigList[i] = NULL;	
}

void ApplicationManager::Run()
{
	ActionType ActType;
	do
	{	
		//1- Read user action
		ActType = pGUI->MapInputToActionType();

		//2- Create the corresponding Action
		Action *pAct = CreateAction(ActType);
		
		//3- Execute the action
		ExecuteAction(pAct);

		//4- Update the interface
		UpdateInterface();	

	}while(ActType != EXIT);
	
}


//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
//Creates an action
Action* ApplicationManager::CreateAction(ActionType ActType) 
{
	Action* newAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_SQUARE:
			newAct = new ActionAddSquare(this);
			break;
		
		case DRAW_CIRC:
			newAct = new ActionAddCircle(this);
			break;
		case DRAW_ELPS:
			newAct = new ActionAddEllipse(this);
			break;

		case DRAW_HEX:
			newAct = new ActionAddHexagon(this);
			break;

		case SELECT_FIG:
			newAct =  new ActionSelectShape(this);
			break;

		case CHNG_DRAW_CLR:
			newAct = new ActionChngDRCol(this);
			break;

		case CHNG_BK_CLR:
			newAct = new ActionChngBGCol(this);
			break;
		case CHNG_FILL_CLR:
			newAct = new ActionChngFillColor(this);
			break;

			//DEL
		case DEL:
			newAct = new ActionDeleteShape(this);
			break;
		case RESIZE:
			newAct = new Resize(this);
			break;

		case EXIT:
			///create ExitAction here
			
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return NULL;
			break;

		default:
			newAct = new ActionSelectShape(this);
			break;

	}	
	return newAct;
}
//////////////////////////////////////////////////////////////////////
//Executes the created Action
void ApplicationManager::ExecuteAction(Action* &pAct) 
{	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	//if(FigCount < MaxFigCount )
		//FigList[FigCount++] = pFig;	
	FigList.push_back(pFig);
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	CFigure* fig = NULL;

	for (auto figure : FigList) {

		if (figure && figure->isBelongTo(x, y))
		{
			fig = figure;
			break;
		}
	}

	return fig;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	pGUI->ClearDrawArea();
	for(int i=0; i<FigList.size(); i++)
		FigList[i]->DrawMe(pGUI);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the interface
GUI *ApplicationManager::GetGUI() const
{	return pGUI; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigList.size(); i++)
		delete FigList[i];
	delete pGUI;
	
}

//====================================================================
//             Deleting a figure from figuers list  --IslamHamza    ||
//====================================================================

//Getting selected shapes from the entire figure list
//void ApplicationManager::UpdateInterface() const

void ApplicationManager::deleteShapes() 
{
	for (int i = 0; i < FigList.size(); i++)
	{
		if (FigList[i]->IsSelected())
		{
			FigList.erase(FigList.begin() + i);
			i--;
		}
	}
}

//==================================================================================
//             changing fill color for a figure from figuers list  --IslamHamza    ||
//===================================================================================

//Getting selected shapes from the entire figure list
//void ApplicationManager::UpdateInterface() const

void ApplicationManager::changeFillColor(color Fclr)
{
	for (int i = 0; i < FigList.size(); i++)
	{
		if (FigList[i]->IsSelected())
		{
			FigList[i]->ChngFillClr(Fclr);
			
		}
	}
}

void ApplicationManager::Resize_figure(GUI* pGUI, float size) const {
	for (int i = 0; i < FigList.size(); i++)
	{
		if (FigList[i]->IsSelected())
		{
			FigList[i]->Resize(pGUI, size);
		}
	}
}

bool ApplicationManager::AnySelected() const
{
	for (int i = 0; i < FigList.size(); i++)
	{
		if (FigList[i]->IsSelected())
		{
			return true;
		}
	}
	return false;
}

