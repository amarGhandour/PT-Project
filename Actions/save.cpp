
#include "save.h"
#include"..\ApplicationManager.h"
#include"..\Figures\CFigure.h"
#include"..\GUI\GUI.h"
#include <iostream>
#include <fstream>
#include <windows.h>
#include <shobjidl.h> 

Save::Save(ApplicationManager* pApp, int FigCount) : Action(pApp)
{
    FileName = "TEST";
    FigCnt = FigCount;    
}
void Save::Execute() {

    GUI* pGUI = pManager->GetGUI();
    ofstream OutFile;
   
		string path = "";
		HRESULT hr = CoInitializeEx(NULL, COINITBASE_MULTITHREADED |
			COINIT_DISABLE_OLE1DDE);
		if (SUCCEEDED(hr))
		{
			IFileSaveDialog* pFileSave;

			// Create the FileOpenDialog object.
			hr = CoCreateInstance(CLSID_FileSaveDialog, NULL, CLSCTX_ALL,
				IID_IFileSaveDialog, reinterpret_cast<void**>(&pFileSave));
			if (SUCCEEDED(hr))
			{
				// Set default extension
				hr = pFileSave->SetDefaultExtension(L"txt");
				if (SUCCEEDED(hr))
				{
					// Show the Open dialog box.
					hr = pFileSave->Show(NULL);

					// Get the file name from the dialog box.
					if (SUCCEEDED(hr))
					{
						IShellItem* pItem;
						hr = pFileSave->GetResult(&pItem);
						if (SUCCEEDED(hr))
						{
							PWSTR pszFilePath;
							hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);
							// Display the file name to the user.
							if (SUCCEEDED(hr))
							{
		
								char buffer[500];
								wcstombs(buffer, pszFilePath, 500);
								path = buffer;
								CoTaskMemFree(pszFilePath);
								//////////////////
								OutFile.open(pszFilePath); 
						
								OutFile << pManager->ConvertToString(UI.DrawColor) << "\t";

								OutFile << pManager->ConvertToString(UI.FillColor) << "\t";

								OutFile << pManager->ConvertToString(UI.BkGrndColor);  
								OutFile << "\n" << FigCnt << "\n";  
								pManager->SaveFig(OutFile);  
								OutFile.close();

							}
							pItem->Release();
						}
					}
					pFileSave->Release();
				}
			}
			CoUninitialize();
		}

		pGUI->CreateToolBar();

		pGUI->CreateDrawToolBar();
   
}

