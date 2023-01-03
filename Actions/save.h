#pragma once
#include "Action.h"


class Save :public Action
{
	string FileName;
	int FigCnt;
public:
	Save(ApplicationManager* pApp, int);

	virtual void Execute();
};

