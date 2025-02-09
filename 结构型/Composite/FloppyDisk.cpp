#include "FloppyDisk.h"

FloppyDisk::FloppyDisk(const char *name)
    : Equipment(name)
{
}

FloppyDisk::~FloppyDisk()
{
}

Watt FloppyDisk::Power()
{
    return Watt();
}

Currency FloppyDisk::NetPrice()
{
    return Currency();
}

Currency FloppyDisk::DiscountPrice()
{
    return Currency();
}
