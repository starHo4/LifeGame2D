#ifndef __World__
#define __World__

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> Array;
typedef vector<Array> Array2D;

class World
{
private:
    int width;
    int height;
    Array2D grid;
    Array2D new_grid;

    void swapGrid();

public:
    World(int, int);

    int getNeighbors(int x, int y);

    void getLife(int x, int y);
    void SetLife(int x, int y, int val);
    void SetNewLife(int x, int y, int val);
    void Bound();

    void print();
};

#endif