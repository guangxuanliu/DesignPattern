#ifndef SCROLLDECORATOR_H_
#define SCROLLDECORATOR_H_

#include "Decorator.h"

class ScrollDecorator : public Decorator
{
public:
    ScrollDecorator(VisualComponent* component);

    virtual void Draw();
    // ...

protected:
    void DrawScroll();
};

#endif // SCROLLDECORATOR_H_