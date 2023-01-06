#ifndef LOADNM
#define LOADNM
#endif
#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include "../Figures/CEllipse.h"
#include "../Figures/CHexagon.h"
#include "../Figures/CSquare.h"
#include "../Figures/CCircle.h"

#include "Load.h"
#include<fstream>
#include <string>
#include <string.h>
#include <iostream>
#include <Windows.h>
#include <iostream>
#include <tchar.h>
#include <windows.h>
#include <shobjidl.h> 





Load::Load(ApplicationManager* pApp) :Action(pApp)
{}


//Execute the action
void Load::Execute()
{

	GUI* pGUI = pManager->GetGUI();
	int figcount = pManager->getFigCount();
	if (figcount > 0)
	{
		int msgboxID = MessageBoxW(
			NULL,
			(LPCWSTR)L"save before load!\n",
			(LPCWSTR)L"file not saved ",
			MB_ICONWARNING | MB_YESNO
		);

		switch (msgboxID)
		{
		case IDYES:
		{	Action* pAct = pManager->CreateAction(SAVE);
		pManager->ExecuteAction(pAct);
		pGUI->PrintMessage("file save load now ");
		break;
		}
		case IDNO:
		{pGUI->PrintMessage("file not save load now ");
		break;
		}
		}
		int msgboxID2 = MessageBoxW(
			NULL,
			(LPCWSTR)L"      load now!            \n",
			(LPCWSTR)L"       loading file          ",
			MB_ICONINFORMATION | MB_OK
		);
	}
	int r, g, b;
	string name;
	int Cnt;
	CFigure* fig = NULL;

	std::ifstream InFile;
	
	HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED |
		COINIT_DISABLE_OLE1DDE);
	if (SUCCEEDED(hr))
	{
		IFileOpenDialog* pFileOpen;

		// Create the FileOpenDialog object.
		hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_ALL,
			IID_IFileOpenDialog, reinterpret_cast<void**>(&pFileOpen));

		if (SUCCEEDED(hr))
		{
			// Show the Open dialog box.
			hr = pFileOpen->Show(NULL);

			// Get the file name from the dialog box.
			if (SUCCEEDED(hr))
			{
				IShellItem* pItem;
				hr = pFileOpen->GetResult(&pItem);
				if (SUCCEEDED(hr))
				{
					PWSTR pszFilePath;
					hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);

					// Display the file name to the user.
					if (SUCCEEDED(hr))
					{
						//MessageBoxW(NULL, pszFilePath, L"File Path", MB_OK);
						InFile.open(pszFilePath);
						CoTaskMemFree(pszFilePath);
						///////////////
						InFile >> r >> g >> b;
						color drawClr(r, g, b);

						InFile >> r >> g >> b;
						color FillClr(r, g, b);

						InFile >> r >> g >> b;
						color bkgclr(r, g, b);

						pGUI->setCrntDrawColor(drawClr);
						pGUI->setCrntFillColor(FillClr);
						pGUI->setCrntBKGrandColor(bkgclr);
						pGUI->ClearDrawArea();

						pManager->ResetFiglist();

						InFile >> Cnt;

						while (Cnt--)          
						{
							InFile >> name;

							if (name == "Square")
								fig = new CSquare;
							else if (name == "Hexagon")
								fig = new CHexagon;

							else if (name == "Ellipse")
								fig = new  CEllipse;

							else if (name == "Circle")
								fig = new  CCircle;

							fig->Load(InFile);  
							pManager->AddFigure(fig); 
						}


						pManager->UpdateInterface();    
						pGUI->PrintMessage("Graph Loaded Successfully");

					}


					pItem->Release();
				}
				if (InFile.fail())
				{
					pGUI->PrintMessage("fail load file ");
				}
			}
			pFileOpen->Release();

		}
		CoUninitialize();
	}



}







