#include "Window.h"

Window::Window(View *contents)
{
}

void Window::DrawContents()
{
}

void Window::Open()
{
}

void Window::Close()
{
}

void Window::Iconify()
{
}

void Window::Deiconify()
{
}

void Window::SetOrigin(const Point &at)
{
}

void Window::SetExtent(const Point &extent)
{
}

void Window::Raise()
{
}

void Window::Lower()
{
}

void Window::DrawLine(const Point &p1, const Point &p2)
{
}

void Window::DrawRect(const Point &p1, const Point &p2)
{
    WindowImp *imp = GetWindowImp();
    if (imp != 0)
    {
        imp->DeviceRect(p1._x, p1._y, p2._x, p2._y);
    }
}

void Window::DrawPolygon(const Point *pa, int n)
{
}

void Window::DrawText(const char *text, const Point &at)
{
}

WindowImp *Window::GetWindowImp()
{
    return nullptr;
}

View *Window::GetView()
{
    return nullptr;
}
