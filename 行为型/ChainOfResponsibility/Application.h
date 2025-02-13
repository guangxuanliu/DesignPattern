#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "HelpHandler.h"

class Application : public HelpHandler
{
public:
    Application(Topic t) : HelpHandler(0, t) {}
    virtual void HandleHelp();
};

#endif // APPLICATION_H_