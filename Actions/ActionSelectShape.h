#pragma once
#include "Action.h"

class ActionSelectShape :public Action
{
public:
    ActionSelectShape(ApplicationManager* pApp);

    void Execute();
};

