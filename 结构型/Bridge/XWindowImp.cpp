#include "XWindowImp.h"

#include <cmath>

XWindowImp::XWindowImp()
{
}

void XWindowImp::DeviceRect(Coord x0, Coord y0, Coord x1, Coord y1)
{
    int x = std::round(std::min(x0, x1));
    int y = std::round(std::min(y0, y1));
    int w = std::round(std::abs(x0 - x1));
    int h = std::round(std::abs(y0 - y1));
    // draw rectangle
}
