#ifndef SIMPLECOMPOSITOR_H_
#define SIMPLECOMPOSITOR_H_

#include "Compositor.h"

class SimpleCompositor : public Compositor
{
public:
    SimpleCompositor();

    virtual int Compose(Coord natural[], Coord stretch[], Coord shrink[],
                        int componentCount, int lineWidth, int breaks[]);
};

#endif // SIMPLECOMPOSITOR_H_