#ifndef WINDOW_H_
#define WINDOW_H_

#include "Common.h"
#include "View.h"
#include "WindowImp.h"

class Window
{
public:
    Window(View *contents);

    virtual void DrawContents();

    virtual void Open();

    virtual void Close();
    virtual void Iconify();
    virtual void Deiconify();

    virtual void SetOrigin(const Point &at);
    virtual void SetExtent(const Point &extent);
    virtual void Raise();
    virtual void Lower();

    virtual void DrawLine(const Point &p1, const Point &p2);
    virtual void DrawRect(const Point &p1, const Point &p2);
    virtual void DrawPolygon(const Point *pa, int n);
    virtual void DrawText(const char *text, const Point &at);

protected:
    WindowImp *GetWindowImp();
    View *GetView();

private:
    WindowImp *_imp;
    View *_contents;
};

#endif // WINDOW_H_