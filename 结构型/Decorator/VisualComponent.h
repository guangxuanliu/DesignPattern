#ifndef VISUALCOMPONENT_H_
#define VISUALCOMPONENT_H_

class VisualComponent
{
public:
    VisualComponent();

    virtual void Draw();
    virtual void Resize();
};

#endif // VISUALCOMPONENT_H_