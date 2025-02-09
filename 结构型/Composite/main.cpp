#include <iostream>

#include "Chassis.h"
#include "FloppyDisk.h"

int main()
{
    // Cabinet *cabinet = new Cabinet("PC Cabinet");
    Chassis *chassis = new Chassis("PC Chassis");
    // cabinet->Add(chassis);

    // Bus *bus = new Bus("MCA Bus");
    // bus->Add(new Card("16Mbs Token Ring"));
    // chassis->Add(bus);
    chassis->Add(new FloppyDisk("3.5in Floppy"));

    // std::cout << "The net price is " << cabinet->NetPrice().Value() << std::endl;

    return 0;
}