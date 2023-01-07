#pragma once
#include"Action.h"
class Exit:public Action
{
	int flag;
public:
	Exit(ApplicationManager* pApp, int flag);


	virtual void Execute();
	
};
