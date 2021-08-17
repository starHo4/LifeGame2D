#include "GLScene.hpp"

#define FPS 50

int window_width = 800;
int window_height = 800;

void GLScene(int argc, char *argv[])
{
    GLScene(800, 800, argc, argv);
}

void GLScene(int x, int y, int argc, char *argv[])
{
    glutInit(&argc, argv);

    glutInitWindowPosition(0, 0);
    glutInitWindowSize(window_width, window_height);

    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);

    glutCreateWindow("Conway's Game of Life");

    glutDisplayFunc(Display);
    glutKeyboardFunc(Keyboard);
    glutReshapeFunc(Reshape);
    glutTimerFunc(1000 / FPS, Update, 0);
}

void Display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

void Keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'q':
    case 'Q':
    case '\033':
        exit(0);
    default:
        break;
    }
}

void Reshape(int w, int h)
{
    if (h == 0)
    {
        h = 1;
    }

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, (double)w / h, 0.1, 100);
}

void Update(int val){
    // ここを次は編集
    glutPostRedisplay();
}