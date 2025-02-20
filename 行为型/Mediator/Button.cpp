#include "Button.h"

Button::Button(DialogDirector *d)
    : Widget(d)
{
}

void Button::SetText(const char *text)
{
}

void Button::HandleMouse(MouseEvent &event)
{
    Changed();
}

// other methods