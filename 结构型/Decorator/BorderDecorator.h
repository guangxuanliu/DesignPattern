#ifndef BORDERDECORATOR_H_
#define BORDERDECORATOR_H_

#include "Decorator.h"

class BorderDecorator : public Decorator
{
public:
    BorderDecorator(VisualComponent* component, int borderWidth);

    virtual void Draw();
    // ...

protected:
    void DrawBorder(int);
    
private:
    int _width;
};

#endif // BORDERDECORATOR_H_