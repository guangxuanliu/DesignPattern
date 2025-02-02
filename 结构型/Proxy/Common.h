#ifndef COMMON_H_
#define COMMON_H_

class Point
{
public:
    Point()
        : _x(0.0), _y(0.0)
    {
    }

    Point(double x, double y)
        : _x(x), _y(y)
    {
    }

public:
    double _x;
    double _y;
};

class Event
{
};

#endif // COMMON_H_