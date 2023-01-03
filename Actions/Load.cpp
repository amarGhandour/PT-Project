#ifndef NOMINMAX
#define NOMINMAX
#endif
#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include "../Figures/CEllipse.h"
#include "../Figures/CHexagon.h"
#include "../Figures/CSquare.h"

#include "Load.h"
#include<fstream>
#include <string>
#include <string.h>
#include <iostream>
#include <iostream>
#include <tchar.h>




Load::Load(ApplicationManager* pApp) :Action(pApp)
{}


//Execute the action
void Load::Execute()
{

	GUI* pGUI = pManager->GetGUI();
	int r, g, b;
	string name;
	int Cnt;
	CFigure* fig = NULL;

	std::ifstream InFile;
	//////////////////////////

	
						InFile.open("TEST.txt");
						InFile >> r >> g >> b;
						color drawClr(r, g, b);

						InFile >> r >> g >> b;
						color FillClr(r, g, b);

						InFile >> r >> g >> b;
						color bkgclr(r, g, b);

					///	if (FillClr == "NON-FILLED")
					//	{
					//		pGUI->setIsFilled(false);
					//	}
					//	else
					//	{
				//			pGUI->setIsFilled(true);

				//		}

						pGUI->setCrntDrawColor(drawClr);
						pGUI->setCrntFillColor(FillClr);
						pGUI->setCrntBKGrandColor(bkgclr);
						pGUI->ClearDrawArea();
						pManager->ResetFiglist();

						InFile >> Cnt;

						while (Cnt)           
						{
							cout << Cnt << endl;
							InFile >> name;
							cout << name << endl;
							if (name == "Square")
								fig = new CSquare;
							//else if (name == "Hexagon")
							//	fig = new CHexagon;

							//else if (name == "Ellipse")
							//	fig = new  CEllipse;


							fig->Load(InFile);  
							pManager->AddFigure(fig); 
							Cnt--;
						}



						pManager->UpdateInterface();     //Draw the figure list
						pGUI->PrintMessage("Graph Loaded Successfully");
						//pGUI->ClearStatusBar();
				////////////////////
				
				if (InFile.fail())
				{
					pGUI->PrintMessage("fail load file ");
				}
}







