#include "PMWindowImp.h"

#include <cmath>

PMWindowImp::PMWindowImp()
{
}

void PMWindowImp::DeviceRect(Coord x0, Coord y0, Coord x1, Coord y1)
{
    Coord left = std::min(x0, x1);
    Coord right = std::max(x0, x1);
    Coord bottom = std::min(y0, y1);
    Coord top = std::max(y0, y1);

    // draw rectangle
}
