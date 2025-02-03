#include "ScrollDecorator.h"

ScrollDecorator::ScrollDecorator(VisualComponent *component)
    : Decorator(component)
{
}

void ScrollDecorator::Draw()
{
    Decorator::Draw();
    DrawScroll();
}

void ScrollDecorator::DrawScroll()
{
}
