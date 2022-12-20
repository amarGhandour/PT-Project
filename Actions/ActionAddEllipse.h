#pragma once
#include "Action.h"
class ActionAddEllipse: public Action
{
public:
	ActionAddEllipse(ApplicationManager* pApp);

	virtual void Execute();

};

