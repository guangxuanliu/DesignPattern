#include <iostream>

#include "Composition.h"
#include "SimpleCompositor.h"
#include "TexCompositor.h"
#include "ArrayCompositor.h"

int main()
{
    Composition composition(new SimpleCompositor);
    composition.Repair();

    Composition composition2(new TexCompositor);
    composition2.Repair();

    Composition composition3(new ArrayCompositor);
    composition3.Repair();

    return 0;
}