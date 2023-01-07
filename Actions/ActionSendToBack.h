#ifndef ACTION_SEND_TO_BACK
#define ACTION_SEND_TO_BACK

#include "Action.h"

//Sending a figure to back
class ActionSendToBack :public Action
{
public:
	ActionSendToBack(ApplicationManager* pApp);

	virtual void Execute();
};
#endif // !ACTION_SEND_TO_BACK
