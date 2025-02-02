#ifndef SHAPE_H_
#define SHAPE_H_

#include "Common.h"

class Manipulator;

class Shape
{
public:
    Shape();

    virtual void BoundingBox(Point &bottomLeft, Point &topRight) const;
    virtual Manipulator *CreateManipulator() const;
};

#endif // SHAPE_H_