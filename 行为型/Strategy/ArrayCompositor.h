#ifndef ARRAYCOMPOSITOR_H_
#define ARRAYCOMPOSITOR_H_

#include "Compositor.h"

class ArrayCompositor : public Compositor
{
public:
    ArrayCompositor();

    virtual int Compose(Coord natural[], Coord stretch[], Coord shrink[],
                        int componentCount, int lineWidth, int breaks[]);
};


#endif // ARRAYCOMPOSITOR_H_