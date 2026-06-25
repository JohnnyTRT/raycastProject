#include "maze.hppgit status"

int main()
{
    Maze maze(41, 41);

    maze.generateMaze();
    maze.addRandomOpenings(40);
    maze.printMaze();

    return 0;
}