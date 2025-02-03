#include <iostream>
#include "Window.h"
#include "BorderDecorator.h"
#include "ScrollDecorator.h"

int main()
{
    Window *window = new Window();
    window->SetContents(
        new BorderDecorator(
            new ScrollDecorator(new VisualComponent()), 10));
            
    return 0;
}