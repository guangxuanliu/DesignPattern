#ifndef BUTTON_H_
#define BUTTON_H_

#include "Widget.h"

class Button : public Widget
{
public:
    Button(Widget *d, Topic t = NO_HELP_TOPIC);
    virtual void HandleHelp();
};

#endif // BUTTON_H_