#ifndef FACTORY_H
#define FACTORY_H

#include "basictypes.h"

class MazeFactory
{
public:
    MazeFactory()
    {
        
    }

    virtual Maze *MakeMaze() const
    {
        return new Maze();
    }

    virtual Wall *MakeWall() const
    {
        return new Wall();
    }

    virtual Room *MakeRoom(int n) const
    {
        return new Room(n);
    }

    virtual Door *MakeDoor(Room *r1, Room *r2) const
    {
        return new Door(r1, r2);
    }
};

#endif