#ifndef ICONWINDOW_H_
#define ICONWINDOW_H_

#include "Window.h"

class IconWindow : public Window
{
public:
    virtual void DrawContents();

private:
    const char *_bitmapName;
};


#endif // ICONWINDOW_H_