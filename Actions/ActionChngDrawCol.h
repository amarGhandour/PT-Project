#ifndef ACTION_CHNG_DR_COL_H
#define ACTION_CHNG_DR_COL_H

#include "Action.h"

//change Drawing color
class ActionChngDRCol : public Action
{
public:
	ActionChngDRCol(ApplicationManager* pApp);

	//change bg color to the ApplicationManager
	virtual void Execute();

};

#endif