#ifndef TEXCOMPOSITOR_H_
#define TEXCOMPOSITOR_H_

#include "Compositor.h"

class TexCompositor : public Compositor
{
public:
    TexCompositor();

    virtual int Compose(Coord natural[], Coord stretch[], Coord shrink[],
                        int componentCount, int lineWidth, int breaks[]);
};

#endif // TEXCOMPOSITOR_H_