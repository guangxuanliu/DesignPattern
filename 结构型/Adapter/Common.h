#ifndef COMMON_H_
#define COMMON_H_

class Point
{
public:
    double _x;
    double _y;

public:
    Point(double x, double y)
        : _x(x), _y(y)
    {
    }
};

typedef double Coord;

#endif // COMMON_H_