// Completed on August 21st by starHo4.
#include "GLScene.hpp"

#define FPS 50

int Size = 794;

World *world;

int window_width = Size;
int window_height = Size;

void GLScene(int argc, char *argv[])
{
    GLScene(Size, Size, argc, argv);
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

    Init();
}

void Display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    Render();
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

    window_width = w;
    window_height = h;

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, Size / 100, 0, Size / 100, -1.0, 1.0);
}

void Update(int val)
{
    world->Update();
    glutPostRedisplay();
    glutTimerFunc(1000 / FPS, Update, 0);
}

void Init()
{
    // Init background color.
    glClearColor((float)237 / 255, (float)237 / 255, (float)255 / 255, 1);

    // Init state of world.
    NewLife();
}

void NewLife()
{
    world = new World(Size, Size);
    for (int i = 0; i < 0.6 * Size * Size; i++)
    {
        int x = rand() % Size + 1;
        int y = rand() % Size + 1;
        world->SetLife(x, y, 1);
    }
}

void Render()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    double len_w = (double)window_width / world->GetWidth() * 0.01;
    double len_h = (double)window_height / world->GetHeight() * 0.01;

    glBegin(GL_QUADS);

    glColor4d((double)2 / 255, (double)2 / 255, (double)163 / 255, (double)64 / 255);

    double xoff = 0;
    double yoff = 0;

    for (int i = 1; i <= Size; i++)
    {
        xoff = 0;
        for (int j = 1; j <= Size; j++)
        {
            if (world->GetLife(i, j))
            {
                glColor4d((double)2 / 255, (double)2 / 255, (double)163 / 255, (double)64 / 255);
                glVertex2d(xoff, yoff);
                glVertex2d(xoff, len_h + yoff);
                glVertex2d(len_w + xoff, len_h + yoff);
                glVertex2d(len_w + xoff, yoff);
            }
            xoff += len_w;
        }
        yoff += len_h;
    }
    glEnd();
}