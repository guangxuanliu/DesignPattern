#ifndef BUTTON_H_
#define BUTTON_H_

#include "Widget.h"

class Button : public Widget
{
public:
    Button(DialogDirector *);
    virtual void SetText(const char *);
    virtual void HandleMouse(MouseEvent &);

    // other methods
};

#endif // BUTTON_H_