#include "ClockTimer.h"
#include "DigitalClock.h"
#include "AnalogClock.h"

int main(int argc, char *argv[])
{
    ClockTimer *timer = new ClockTimer();
    DigitalClock *digitalClock = new DigitalClock(timer);
    AnalogClock *analogClock = new AnalogClock(timer);

    return 0;
}