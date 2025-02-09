#ifndef EQUIPMENT_H_
#define EQUIPMENT_H_

#include "Common.h"

class Equipment
{
public:
    virtual ~Equipment();

    const char *Name() { return _name; }

    virtual Watt Power();
    virtual Currency NetPrice();
    virtual Currency DiscountPrice();

    virtual void Add(Equipment *);
    virtual void Remove(Equipment *);

protected:
    Equipment(const char *);

private:
    const char *_name;
};

#endif // EQUIPMENT_H_