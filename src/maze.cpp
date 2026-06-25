#include "maze.hpp"
#include <iostream>
#include <vector>
#include <stack>
#include <cstdlib>
#include <ctime>
#include <utility>

using namespace std;

Maze::Maze(int r, int c)
{
    rows = r;
    cols = c;

    if (rows % 2 == 0)
        rows++;

    if (cols % 2 == 0)
        cols++;

    startRow = 1;
    startCol = 1;

    exitRow = rows - 2;
    exitCol = cols - 2;

    grid = vector<vector<int>>(rows, vector<int>(cols, 1));
}

bool Maze::isInBounds(int row, int col) const
{
    return row > 0 && row < rows - 1 &&
           col > 0 && col < cols - 1;
}

void Maze::generateMaze()
{
    srand(time(0));

    grid = vector<vector<int>>(rows, vector<int>(cols, 1));

    stack<pair<int, int>> cellStack;

    int currentRow = startRow;
    int currentCol = startCol;

    grid[currentRow][currentCol] = 0;
    cellStack.push(make_pair(currentRow, currentCol));

    while (!cellStack.empty())
    {
        currentRow = cellStack.top().first;
        currentCol = cellStack.top().second;

        vector<pair<int, int>> neighbors;

        int directions[4][2] =
        {
            {-2, 0},
            {2, 0},
            {0, -2},
            {0, 2}
        };

        for (int i = 0; i < 4; i++)
        {
            int newRow = currentRow + directions[i][0];
            int newCol = currentCol + directions[i][1];

            if (isInBounds(newRow, newCol) &&
                grid[newRow][newCol] == 1)
            {
                neighbors.push_back(make_pair(newRow, newCol));
            }
        }

        if (!neighbors.empty())
        {
            int randomIndex = rand() % neighbors.size();

            int nextRow = neighbors[randomIndex].first;
            int nextCol = neighbors[randomIndex].second;

            int wallRow = currentRow + (nextRow - currentRow) / 2;
            int wallCol = currentCol + (nextCol - currentCol) / 2;

            grid[wallRow][wallCol] = 0;
            grid[nextRow][nextCol] = 0;

            cellStack.push(make_pair(nextRow, nextCol));
        }
        else
        {
            cellStack.pop();
        }
    }

    grid[startRow][startCol] = 0;
    grid[exitRow][exitCol] = 0;
}

void Maze::addRandomOpenings(int numberOfOpenings)
{
    for (int i = 0; i < numberOfOpenings; i++)
    {
        int row = 1 + rand() % (rows - 2);
        int col = 1 + rand() % (cols - 2);

        grid[row][col] = 0;
    }
}

void Maze::printMaze() const
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (row == startRow && col == startCol)
                cout << "S";
            else if (row == exitRow && col == exitCol)
                cout << "E";
            else if (grid[row][col] == 1)
                cout << "#";
            else
                cout << " ";
        }

        cout << endl;
    }
}

const vector<vector<int>>& Maze::getGrid() const
{
    return grid;
}

int Maze::getStartRow() const
{
    return startRow;
}

int Maze::getStartCol() const
{
    return startCol;
}

int Maze::getExitRow() const
{
    return exitRow;
}

int Maze::getExitCol() const
{
    return exitCol;
}

bool Maze::isWall(int row, int col) const
{
    if (row < 0 || row >= rows || col < 0 || col >= cols)
        return true;

    return grid[row][col] == 1;
}

bool Maze::hasWon(int playerRow, int playerCol) const
{
    return playerRow == exitRow && playerCol == exitCol;
}