#include <GL/glut.h>

void Initial(void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
}

void Display(void)
{
}

void no()
{
    GLuint OlympicRings = glGenLists(1);
    glNewList(OlympicRings, GL_COMPILE);
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(-22.0, 0.0, 0.0);
    glutSolidTorus(0.5, 20.0, 15, 50);
    glColor3f(0.0, 1.0, 0.0);
    glTranslatef(44.0, 0.0, 0.0);
    glutSolidTorus(0.5, 20.0, 15, 50);
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(-22.0, 30.0, 0.0);
    glutSolidTorus(0.5, 20.0, 15, 50);
    glColor3f(0.0, 0.0, 1.0);
    glTranslatef(-42.0, 0.0, 0.0);
    glutSolidTorus(0.5, 20.0, 15, 50);
    glColor3f(1.0, 0.0, 0.0);
    glTranslatef(84.0, 0.0, 0.0);
    glutSolidTorus(0.5, 20.0, 15, 50);
    glEndList();
    glCallList(OlympicRings);

int main(int argc, char * argv[])
{

    return 0;
}
