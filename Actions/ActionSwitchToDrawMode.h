#ifndef ACTION_SWICH_TO_DRAW_MODE
#define ACTION_SWICH_TO_DRAW_MODE

#include "Action.h"

class ActionSwitchToDrawMode :public Action {
public:
	ActionSwitchToDrawMode(ApplicationManager* pApp);
	virtual void Execute();
};

#endif 

