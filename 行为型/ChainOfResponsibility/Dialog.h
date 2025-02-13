#ifndef DIALOG_H_
#define DIALOG_H_

#include "Widget.h"

class Dialog : public Widget
{
public:
    Dialog(HelpHandler *h, Topic t = NO_HELP_TOPIC);
    virtual void HandleHelp();
};

#endif // DIALOG_H_