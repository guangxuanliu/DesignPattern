#ifndef COMMON_H_
#define COMMON_H_

class Watt
{
};

class Currency
{
public:
    Currency(int value = 0)
        : _value(value)
    {
    }

    Currency operator+(const Currency &rhs)
    {
        return Currency(_value + rhs._value);
    }

    Currency operator+=(const Currency &rhs)
    {
        _value += rhs._value;
        return *this;
    }

private:
    int _value;
};

#endif // COMMON_H_