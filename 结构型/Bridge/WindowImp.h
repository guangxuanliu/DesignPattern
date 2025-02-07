#ifndef WINDOWIMP_H_
#define WINDOWIMP_H_

#include "Common.h"

class WindowImp
{
public:
    virtual void ImpTop() = 0;
    virtual void ImpBottom() = 0;
    virtual void ImpSetExtent(const Point &extent) = 0;
    virtual void ImpSetOrigin(const Point &origin) = 0;

    virtual void DeviceRect(Coord, Coord, Coord, Coord) = 0;
    virtual void DeviceText(const char *, Coord, Coord) = 0;
    virtual void DeviceBitmap(const char *, Coord, Coord) = 0;

protected:
    WindowImp();
};

#endif // WINDOWIMP_H_