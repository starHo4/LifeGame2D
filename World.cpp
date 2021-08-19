#include "World.hpp"

World::World(int w, int h)
{
    width = w;
    height = h;
    grid = new Array2D(width + 2, Array(height + 2, 0));
    new_grid = new Array2D(width + 2, Array(height + 2, 0));
}

void World::Bound(){
    grid[0][0] = grid[width][height];
    grid[width + 1][0] = grid[1][height];
    grid[0][height + 1] = grid[width][1];
    grid[width + 1][height + 1] = grid[1][1];

    
}