#ifndef GRAPHIC_H_
#define GRAPHIC_H_

#include "Common.h"
#include <iostream>

class Graphic
{
public:
    Graphic();

    virtual void Draw(const Point& at) = 0;
    virtual void HandleMouse(Event& event) = 0;
    virtual const Point& GetExtent() = 0;
    virtual void Load(std::istream& from) = 0;
    virtual void Save(std::ostream& to) = 0;
};

#endif // GRAPHIC_H_