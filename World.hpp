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

public:
    World(int, int);

    int getNeighbors(int, int);

    void SetNum(int x, int y, int val);
    void Bound();

    void print();
};

#endif