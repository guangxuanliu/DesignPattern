#include "Shape.h"
#include "Manipulator.h"

Shape::Shape()
{
}

void Shape::BoundingBox(Point &bottomLeft, Point &topRight) const
{
}

Manipulator *Shape::CreateManipulator() const
{
    return nullptr;
}
