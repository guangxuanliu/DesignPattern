#ifndef WIDGET_H_
#define WIDGET_H_

#include "DialogDirector.h"

class MouseEvent;

class Widget
{
public:
    Widget(DialogDirector *);
    virtual void Changed();
    virtual void HandleMouse(MouseEvent &);

    // other methods

private:
    DialogDirector *_director;
};

class MouseEvent
{
};

#endif // WIDGET_H_