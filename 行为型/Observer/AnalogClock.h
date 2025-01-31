#ifndef ANALOGCLOCK_H_
#define ANALOGCLOCK_H_

#include "Observer.h"

class ClockTimer;

class AnalogClock : public Observer
{
public:
    AnalogClock(ClockTimer *);
    virtual ~AnalogClock();

    virtual void Update(Subject *);
    virtual void Draw();

private:
    ClockTimer *_subject;
};

#endif // ANALOGCLOCK_H_