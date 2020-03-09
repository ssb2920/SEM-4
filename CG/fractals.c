#define PI 3.141592
#include<stdio.h> 
#include<math.h>
#include<GL/glut.h>
void branch(float x, float y, float len, float theta)
{
	float x2 = x + len * cos(theta) * 10.0;
	float y2 = y + len * sin(theta) * 10.0;


	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2f(x, y);
	glVertex2f(x2, y2);
	glEnd();

	if (len > 0)
	{
		branch(x2, y2, len - 1, theta + PI / 8);
		branch(x2, y2, len - 1, theta - PI / 8);
	}
}


void disp()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1, 1);
	branch(200, -250, 10, PI / 2); // THE MAIN BARK OF TREE
	glFlush();
}


int main(int argv, char** argc)
{
	glutInit(&argv, argc);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Fractal Tree");
	gluOrtho2D(-300, 900, -300, 900);
	glutDisplayFunc(disp);
	glutMainLoop();

}