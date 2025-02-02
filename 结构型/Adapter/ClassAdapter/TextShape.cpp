#include "TextShape.h"
#include "Manipulator.h"

TextShape::TextShape()
{
}

void TextShape::BoundingBox(Point &bottomLeft, Point &topRight) const
{
    Coord bottom, left, width, height;

    GetOrigin(bottom, left);
    GetExtent(width, height);

    bottomLeft = Point(bottom, left);
    topRight = Point(bottom + height, left + width);
}

bool TextShape::IsEmpty() const
{
    return TextView::IsEmpty();
}

Manipulator *TextShape::CreateManipulator() const
{
    return nullptr;
}
