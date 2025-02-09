#include "CompositeEquipment.h"

CompositeEquipment::~CompositeEquipment()
{
}

Watt CompositeEquipment::Power()
{
    return Watt();
}

Currency CompositeEquipment::NetPrice()
{
    Currency total = 0;
    for (auto &e : _equipment)
    {
        total += e->NetPrice();
    }

    return total;
}

Currency CompositeEquipment::DiscountPrice()
{
    return Currency();
}

void CompositeEquipment::Add(Equipment *)
{
}

void CompositeEquipment::Remove(Equipment *)
{
}

CompositeEquipment::CompositeEquipment(const char *name)
    : Equipment(name)
{
}
