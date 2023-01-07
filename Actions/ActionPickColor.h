#ifndef ACTION_PICK_COLOR
#define ACTION_PICK_COLOR

#include "Action.h"
class ActionPickColor :public Action
{
	static string lastColor;
	int rightAns;
	int wrongAns;
	void score(int, string);

public:
	ActionPickColor(ApplicationManager* pApp);
	void Execute();

};

#endif