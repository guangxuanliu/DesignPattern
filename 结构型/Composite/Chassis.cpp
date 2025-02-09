#include "Chassis.h"

Chassis::Chassis(const char *name)
    : CompositeEquipment(name)
{
}

Chassis::~Chassis()
{
}

Watt Chassis::Power()
{
    return Watt();
}

Currency Chassis::NetPrice()
{
    return Currency();
}

Currency Chassis::DiscountPrice()
{
    return Currency();
}
