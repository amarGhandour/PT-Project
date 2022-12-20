#ifndef ACTION_CHNG_BG_COL_H
#define ACTION_CHNG_BG_COL_H

#include "Action.h"

//change BG color
class ActionChngBGCol : public Action
{
public:
	ActionChngBGCol(ApplicationManager* pApp);

	//change bg color to the ApplicationManager
	virtual void Execute();

};

#endif