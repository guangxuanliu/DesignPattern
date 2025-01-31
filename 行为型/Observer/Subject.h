#ifndef SUBJECT_H_
#define SUBJECT_H_

#include <list>
#include "Observer.h"

class Subject
{
public:
    virtual ~Subject();

    virtual void Attach(Observer *);
    virtual void Detach(Observer *);
    virtual void Notify();

protected:
    Subject();

private:
    std::list<Observer *> _observers;
};

#endif // SUBJECT_H_