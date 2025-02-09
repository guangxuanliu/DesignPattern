#ifndef CHASSIS_H_
#define CHASSIS_H_

#include "CompositeEquipment.h"

class Chassis : public CompositeEquipment
{
public:
    Chassis(const char *name);

    virtual ~Chassis();

    virtual Watt Power();

    virtual Currency NetPrice();

    virtual Currency DiscountPrice();
};

#endif // CHASSIS_H_