#ifndef COMPOSITEEQUIPMENT_H_
#define COMPOSITEEQUIPMENT_H_

#include "Equipment.h"

#include <list>

class CompositeEquipment : public Equipment
{
public:
    virtual ~CompositeEquipment();

    virtual Watt Power();
    virtual Currency NetPrice();
    virtual Currency DiscountPrice();

    virtual void Add(Equipment *);
    virtual void Remove(Equipment *);

protected:
    CompositeEquipment(const char *);

private:
    std::list<Equipment *> _equipment;
};

#endif // COMPOSITEEQUIPMENT_H_