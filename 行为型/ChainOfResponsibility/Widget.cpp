#include "Widget.h"

Widget::Widget(Widget *w, Topic t)
    : HelpHandler(w, t), _parent(w)
{
}