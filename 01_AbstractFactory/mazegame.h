#ifndef MAZEGAME_H
#define MAZEGAME_H

#include "factory.h"

class MazeGame
{
public:
    MazeGame()
    {
    }

    // 创建迷宫，bad example
    Maze *bad_CreateMaze();

    // 创建迷宫，使用抽象工厂模式，good example
    Maze *good_CreateMaze(MazeFactory *factory);

private:
};

Maze *MazeGame::bad_CreateMaze()
{
    Maze *aMaze = new Maze();
    Room *r1 = new Room(1);
    Room *r2 = new Room(2);
    Door *theDoor = new Door(r1, r2);

    aMaze->AddRoom(r1);
    aMaze->AddRoom(r2);

    r1->SetSide(North, new Wall());
    r1->SetSide(East, theDoor);
    r1->SetSide(Sourth, new Wall());
    r1->SetSide(West, new Wall());

    r2->SetSide(North, new Wall());
    r2->SetSide(East, new Wall());
    r2->SetSide(Sourth, new Wall());
    r2->SetSide(West, theDoor);

    return aMaze;
}

Maze *MazeGame::good_CreateMaze(MazeFactory *factory)
{
    Maze *aMaze = factory->MakeMaze();
    Room *r1 = factory->MakeRoom(1);
    Room *r2 = factory->MakeRoom(2);
    Door *aDoor = factory->MakeDoor(r1, r2);

    aMaze->AddRoom(r1);
    aMaze->AddRoom(r2);

    r1->SetSide(North, factory->MakeWall());
    r1->SetSide(East, aDoor);
    r1->SetSide(Sourth, factory->MakeWall());
    r1->SetSide(West, factory->MakeWall());

    r2->SetSide(North, factory->MakeWall());
    r2->SetSide(East, factory->MakeWall());
    r2->SetSide(Sourth, factory->MakeWall());
    r2->SetSide(West, aDoor);

    return aMaze;
}

#endif