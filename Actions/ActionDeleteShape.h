#ifndef ACTION_DELETE_SHAPE
#define ACTION_DELETE_SHAPE

#include "Action.h"

//Deleting a shape
class ActionDeleteShape :public Action
{
public:
	ActionDeleteShape(ApplicationManager* pApp);



	virtual void Execute();
};

#endif // !ACTION_DELETE_SHAPE
