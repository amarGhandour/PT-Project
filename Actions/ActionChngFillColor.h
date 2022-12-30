#ifndef ACTION_CHNG_FILL_COLOR
#define ACTION_CHNG_FILL_COLOR

#include "Action.h"

//Action change fill
class ActionChngFillColor :public Action
{
public:
	ActionChngFillColor (ApplicationManager* pApp);

	virtual void Execute();
};
#endif // !ACTION_CHNG_FILL_COLOR
