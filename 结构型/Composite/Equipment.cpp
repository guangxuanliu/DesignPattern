#include "Equipment.h"

Equipment::~Equipment()
{
}

Watt Equipment::Power()
{
    return Watt();
}

Currency Equipment::NetPrice()
{
    return Currency();
}

Currency Equipment::DiscountPrice()
{
    return Currency();
}

void Equipment::Add(Equipment *)
{
}

void Equipment::Remove(Equipment *)
{
}

Equipment::Equipment(const char *)
{
}
