#ifndef PMWINDOWIMP_H_
#define PMWINDOWIMP_H_

#include "Common.h"
#include "WindowImp.h"

class PMWindowImp : public WindowImp
{
public:
    PMWindowImp();

    virtual void DeviceRect(Coord, Coord, Coord, Coord);

    // remainder of public interface...
};

#endif // PMWINDOWIMP_H_