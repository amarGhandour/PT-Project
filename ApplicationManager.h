#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include <vector>
#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\GUI.h"

class Action;	//Forward Declaration


//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	//CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	vector <CFigure*> FigList;
	//Pointers to Input and Output classes
	GUI* pGUI;
	

public:	
	ApplicationManager(); 
	~ApplicationManager();

	void Run();		//to run the application
	
	// -- Action-Related Functions
	Action* CreateAction(ActionType);
	void ExecuteAction(Action*&) ; //Execute an action
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig); //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
		
	// -- Interface Management Functions	
	GUI *GetGUI() const; //Return pointer to the interface
	void UpdateInterface() const;	//Redraws all the drawing window	


	//-Deleting shapes
	void deleteShapes() ;

	//changing fill color
	void changeFillColor(color Fclr);

	void changeSelectedDrawingsColor(color Drcolor);
	void Resize_figure(GUI* pGUI, float size) const;

	bool AnySelected() const;
	string ConvertToString(color c) const;
	void SaveFig(ofstream& Out);
	void ResetFiglist();

	int getFigCount() const;
	void unselectAll() const;
	vector<CFigure*> getFiguresList() const;
	CFigure* getRandomFigure() const;

	bool ApplicationManager::hasDifferentColors() const;
	void ApplicationManager::displayAllFigures() const;
};

#endif