#ifndef TEXTSHAPE_H_
#define TEXTSHAPE_H_

#include "Common.h"
#include "Shape.h"
#include "TextView.h"

class Manipulator;

/**
 * @brief 对象适配器，维护一个指向TextView对象的指针
 * 
 */
class TextShape : public Shape
{
public:
    TextShape(TextView*);

    virtual void BoundingBox(Point& bottomLeft, Point& topRight) const;
    virtual bool IsEmpty() const;
    virtual Manipulator *CreateManipulator() const;

private:
    TextView* _text;
};

#endif // TEXTSHAPE_H_