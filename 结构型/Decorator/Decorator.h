#ifndef DECORATOR_H_
#define DECORATOR_H_

#include "VisualComponent.h"

class Decorator : public VisualComponent
{
public:
    Decorator(VisualComponent* component);

    virtual void Draw();
    virtual void Resize();
    // ...

private:
    VisualComponent* _component;
};

#endif // DECORATOR_H_