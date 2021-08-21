// Completed on August 21st by starHo4.
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
    // Constructor
    World(int, int);

    // Getter
    int GetWidth();
    int GetHeight();

    int GetNeighbors(int x, int y);

    int GetLife(int x, int y);
    void SetLife(int x, int y, int val);
    void SetNewLife(int x, int y, int val);
    void Bound();

    void Update();

    void Print();
};

#endif