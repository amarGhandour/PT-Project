#include "Action.h"

class ActionSwitchToPlay : public Action {
public:
	ActionSwitchToPlay(ApplicationManager* pApp);

	//Executes the switch to play mode
	virtual void Execute();
};
