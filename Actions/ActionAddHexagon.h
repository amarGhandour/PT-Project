#pragma once
#include "Action.h"

class ActionAddHexagon :
    public Action
{
public:
    ActionAddHexagon(ApplicationManager *pApp);

    void Execute();
};

