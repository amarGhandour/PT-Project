#ifndef ACTION_GENERAL
#define ACTION_GENERAL
#include "ActionSelectShape.h"

class ActionGeneral :public ActionSelectShape
{
public:
	ActionGeneral(ApplicationManager* pApp);

	virtual void Execute();
};

#endif ACTION_GENERAL //!ACTION _GENERAL
