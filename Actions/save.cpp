
#include "save.h"
#include"..\ApplicationManager.h"
#include"..\Figures\CFigure.h"
#include"..\GUI\GUI.h"
#include <iostream>
#include <fstream>


Save::Save(ApplicationManager* pApp, int FigCount) : Action(pApp)
{
    FileName = "TEST";
    FigCnt = FigCount;    
}
void Save::Execute() {


    GUI* pGUI = pManager->GetGUI();
    ofstream OutFile;
    //object of ofstream to write on the disk
    pGUI->PrintMessage("Please write a valid name then press ENTER");
    //bool flag = false;
  //  if (OutFile.fail()) {
  //      flag = true;
  //  }

  //  while (flag)
 //   {
  //      pGUI->PrintMessage("Please write a valid name then press ENTER");
    //    FileName = pGUI->GetSrting();
        OutFile.open(FileName + ".txt");
  //      if (OutFile.good())
    //        flag = false;
 //   }
//
  //  OutFile.open(FileName); // create a file with FileName and .txt exetention
    OutFile << pManager->ConvertToString(UI.DrawColor) << "\t";
    
    OutFile << pManager->ConvertToString(UI.FillColor) << "\t";

    OutFile << pManager->ConvertToString(UI.BkGrndColor);  //Write the Current Draw Color
    OutFile << "\n" << FigCnt << "\n";  //and Current Fill Color and in the second line write the number of figures
    pManager->SaveFig(OutFile);  //Now Start Saving each figure proccess
    OutFile.close();

}

