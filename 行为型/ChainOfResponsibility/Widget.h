#ifndef WIDGET_H_
#define WIDGET_H_

#include "HelpHandler.h"

class Widget : public HelpHandler
{
protected:
    Widget(Widget *parent, Topic t = NO_HELP_TOPIC);

private:
    Widget *_parent;
};

#endif // WIDGET_H_