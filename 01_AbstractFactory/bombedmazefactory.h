#ifndef BOMBEDMAZEFACTORY_H
#define BOMBEDMAZEFACTORY_H

#include "factory.h"

class BombedWall : public Wall
{
};

class RoomWithABobm : public Room
{
public:
    RoomWithABobm(int n)
        : Room(n)
    {
    }
};

class BombedMazeFactory : public MazeFactory
{
public:
    Wall *MakeWall() const
    {
        return new BombedWall();
    }

    Room *MakeRoom(int n) const
    {
        return new RoomWithABobm(n);
    }
};

#endif