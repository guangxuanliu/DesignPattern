#include <iostream>
using namespace std;

#include "mazegame.h"
#include "bombedmazefactory.h"
#include "enchantedmazefactory.h"

int main()
{
    cout << "Abstract Factory" << endl;

    MazeGame badexample_game;
    Maze *badexample_maze = badexample_game.bad_CreateMaze();

    MazeGame goodexample_game1;
    BombedMazeFactory bombedMazeFactory;
    Maze *goodexample_maze1 = goodexample_game1.good_CreateMaze(&bombedMazeFactory);

    MazeGame goodexample_game2;
    EnchantedMazeFactory enchantedMazeFactory;
    Maze *goodexample_maze2 = goodexample_game2.good_CreateMaze(&enchantedMazeFactory);

    return 0;
}