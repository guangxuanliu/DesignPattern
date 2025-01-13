#ifndef ENCHANTEMAZEFACTORY_H
#define ENCHANTEMAZEFACTORY_H

#include "factory.h"

class Spell
{
};

class EnchantedRoom : public Room
{
public:
    EnchantedRoom(int n, Spell *)
        : Room(n)
    {
    }
};

class DoorNeedingSpell : public Door
{
public:
    DoorNeedingSpell(Room *r1, Room *r2)
        : Door(r1, r2)
    {
    }
};

class EnchantedMazeFactory : public MazeFactory
{
public:
    EnchantedMazeFactory()
    {
    }

    virtual Room *MakeRoom(int n) const
    {
        return new EnchantedRoom(n, CastSpell());
    }

    virtual Door *MakeDoor(Room *r1, Room *r2) const
    {
        return new DoorNeedingSpell(r1, r2);
    }

protected:
    Spell *CastSpell() const
    {
        Spell *s;
        // ...
        return s;
    }
};

#endif