#include "Button.h"

Button::Button(Widget *d, Topic t)
    : Widget(d, t)
{
}

void Button::HandleHelp()
{
    if (HasHelp())
    {
        // offer help on the button
    }
    else
    {
        HelpHandler::HandleHelp();
    }
}
