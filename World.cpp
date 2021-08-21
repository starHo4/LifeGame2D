// Completed on August 21st by starHo4.
#include "World.hpp"

void World::SwapGrid()
{
    swap(grid, new_grid);
}

// Constructor
World::World(int w, int h)
{
    width = w;
    height = h;
    grid = Array2D(width + 2, Array(height + 2, 0));
    new_grid = Array2D(width + 2, Array(height + 2, 0));
}

// Getter
int World::GetWidth()
{
    return width;
}

int World::GetHeight()
{
    return height;
}

int World::GetNeighbors(int x, int y)
{
    int count = 0;

    // Moore neigborhood
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (i == 0 && j == 0)
            {
                continue;
            }
            count += grid[x + i][y + j];
        }
    }
    return count;
}

int World::GetLife(int x, int y)
{
    return grid[x][y];
}

void World::SetLife(int x, int y, int val)
{
    grid[x][y] = val;
}

void World::SetNewLife(int x, int y, int val)
{
    new_grid[x][y] = val;
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

void World::Update()
{
    // Bound();
    for (int i = 1; i <= width; i++)
    {
        for (int j = 1; j <= height; j++)
        {
            int num = GetNeighbors(i, j);
            if (num == 2)
            {
                SetNewLife(i, j, GetLife(i, j));
            }
            if (num == 3)
            {
                SetNewLife(i, j, 1);
            }
            if (num != 2 && num != 3)
            {
                SetNewLife(i, j, 0);
            }
        }
    }
    SwapGrid();
}

void World::Print()
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