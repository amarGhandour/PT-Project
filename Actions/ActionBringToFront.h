#ifndef ACTION_BRING_TO_FRONT
#define ACTION_BRING_TO_FRONT

#include "Action.h"

//Bringing a figure to Front
class ActionBringToFront :public Action
{
public:
	ActionBringToFront(ApplicationManager* pApp);

	virtual void Execute();
};
#endif // !ACTION_SEND_TO_BACK
