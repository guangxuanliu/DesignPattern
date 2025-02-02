#ifndef TEXTSHAPE_H_
#define TEXTSHAPE_H_

#include "Common.h"
#include "Shape.h"
#include "TextView.h"

class Manipulator;

/**
 * @brief 类适配器，公共方式继承接口，私有方式继承接口的实现
 * 
 */
class TextShape : public Shape, private TextView
{
public:
    TextShape();

    virtual void BoundingBox(Point& bottomLeft, Point& topRight) const;
    virtual bool IsEmpty() const;
    virtual Manipulator *CreateManipulator() const;

};

#endif // TEXTSHAPE_H_