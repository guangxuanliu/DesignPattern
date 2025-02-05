#include "Composition.h"

#include "Compositor.h"

Composition::Composition(Compositor *compositor)
    : _compositor(compositor)
{
}

void Composition::Repair()
{
    Coord *natural;
    Coord *stretchability;
    Coord *shrinkability;
    int componentCount;
    int *breaks;

    // Prepare the arrays with the desired component sizes
    // ...

    // determine where the breaks are:
    int breakCount;
    breakCount = _compositor->Compose(natural, stretchability, shrinkability,
                                      componentCount, _lineWidth, breaks);
    // Lay out components according to breaks
    // ...
}
