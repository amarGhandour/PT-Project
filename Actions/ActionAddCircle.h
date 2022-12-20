#ifndef ACTION_ADD_CIRCLE_H
#define ACTION_ADD_CIRCLE_H

#include "Action.h"

class ActionAddCircle :
    public Action
{

public:
    ActionAddCircle(ApplicationManager *pApp);

    void Execute();
};

#endif 
