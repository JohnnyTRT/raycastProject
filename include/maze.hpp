<<<<<<< HEAD
#ifndef MAZE_H
#define MAZE_H

#include <vector>

class Maze
{
public:
    Maze(int rows = 21, int cols = 21);

    void generateMaze();
    void addRandomOpenings(int numberOfOpenings);
    void printMaze() const;

    const std::vector<std::vector<int>>& getGrid() const;

    int getStartRow() const;
    int getStartCol() const;
    int getExitRow() const;
    int getExitCol() const;

    bool isWall(int row, int col) const;
    bool hasWon(int playerRow, int playerCol) const;

private:
    int rows;
    int cols;

    int startRow;
    int startCol;
    int exitRow;
    int exitCol;

    std::vector<std::vector<int>> grid;

    bool isInBounds(int row, int col) const;
};

#endif
=======
//header file for maze

class maze{

};
>>>>>>> e518e76f13a7b5b1f8fa965a02c2e4d527f72bff
