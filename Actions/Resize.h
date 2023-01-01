#include "Action.h"
#include "ActionSelectShape.h"

class Resize : public Action
{
public:
	 Resize(ApplicationManager* pApp);

	//Add resize to the ApplicationManager
	virtual void Execute();
};
