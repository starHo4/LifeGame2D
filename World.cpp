#include "World.hpp"

World::World(int w, int h)
{
    width = w;
    height = h;
    grid = Array2D(width + 2, Array(height + 2, 0));
    new_grid = Array2D(width + 2, Array(height + 2, 0));
}

void World::SetNum(int x, int y, int val)
{
    grid[x + 1][y + 1] = val;
}

void World::Bound()
{
    grid[0][0] = grid[width][height];
    grid[width + 1][0] = grid[1][height];
    grid[0][height + 1] = grid[width][1];
    grid[width + 1][height + 1] = grid[1][1];

    grid[0] = grid[width];
    grid[width + 1] = grid[1];
    for (int i = 0; i < grid[0].size(); i++)
    {
        grid[i][0] = grid[i][height];
        grid[i][height + 1] = grid[i][1];
    }
}

void World::print()
{
    // cout << grid->size() << endl;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid.size(); j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}