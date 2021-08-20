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

    void SwapGrid();

public:
    World(int, int);

    int GetNeighbors(int x, int y);

    void GetLife(int x, int y);
    void SetLife(int x, int y, int val);
    void SetNewLife(int x, int y, int val);
    void Bound();

    void Update();

    void Print();
};

#endif