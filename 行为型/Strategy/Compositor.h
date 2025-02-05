#ifndef COMPOSITOR_H_
#define COMPOSITOR_H_

#include "Common.h"

class Compositor
{
public:
    virtual int Compose(Coord natural[], Coord stretch[], Coord shrink[],
                        int componentCount, int lineWidth, int breaks[]) = 0;

protected:
    Compositor();
};

#endif // COMPOSITOR_H_