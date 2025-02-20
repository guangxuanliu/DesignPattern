#include "Widget.h"

Widget::Widget(DialogDirector *director)
    : _director(director)
{
}

void Widget::Changed()
{
    _director->WidgetChanged(this);
}

void Widget::HandleMouse(MouseEvent &event)
{
    // do something
}