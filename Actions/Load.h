#pragma once
#include "Action.h"
class Load :
    public Action
{
public:
    Load(ApplicationManager* pApp);

    void Execute();
};

