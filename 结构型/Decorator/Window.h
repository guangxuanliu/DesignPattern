#ifndef WINDOW_H_
#define WINDOW_H_

#include "VisualComponent.h"

class Window
{
public:
    void SetContents(VisualComponent *contents);

    // ...

private:
    VisualComponent *_contents;
};

#endif // WINDOW_H_