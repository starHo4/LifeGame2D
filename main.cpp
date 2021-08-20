#include "GLScene.hpp"
using namespace std;

int main(int argc, char *argv[])
{
    // GLScene(argc, argv);
    // glutMainLoop();

    /* test */
    World w(4, 4);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            w.SetNum(i, j, 4 * i + j + 1);
        }
    }
    w.Bound();
    w.print();
}