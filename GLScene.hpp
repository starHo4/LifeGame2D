// Completed on August 21st by starHo4.
#ifndef __GLScene__
#define __GLScene__

#include <iostream>
#include <GLUT/glut.h>

#include "World.hpp"

using namespace std;

void GLScene(int argc, char *argv[]);
void GLScene(int x, int y, int argc, char *argv[]);

void Display();
void Keyboard(unsigned char key, int x, int y);
void Reshape(int w, int h);
void Update(int val);

void Init();
void NewLife();

void Render();

#endif