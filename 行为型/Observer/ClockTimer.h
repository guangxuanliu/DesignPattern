#ifndef CLOCKTIMER_H_
#define CLOCKTIMER_H_

#include "Subject.h"

class ClockTimer : public Subject
{
public:
    ClockTimer();

    virtual int GetHour();
    virtual int GetMinute();
    virtual int GetSecond();

    void Tick();
};

#endif // CLOCKTIMER_H_