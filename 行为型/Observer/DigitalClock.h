#ifndef DIGITALCLOCK_H_
#define DIGITALCLOCK_H_

#include "Observer.h"

class ClockTimer;

class DigitalClock : public Observer
{
public:
    DigitalClock(ClockTimer *);
    virtual ~DigitalClock();

    virtual void Update(Subject *);

    virtual void Draw();

private:
    ClockTimer *_subject;
};

#endif // DIGITALCLOCK_H_