#include<stdio.h> 
#include<math.h> 
#include<GL/glut.h>
float P[2] = { 50,50 };
float r = 50;

void midpointCircle()
{
	glBegin(GL_POINTS);
	float x1, y1;
	x1 = P[0];
	y1 = P[1];
	float x, y, p;
	x = 0;
	y = r;
	p = 1 - r;
	while (x < y)
	{ // iterates to draw the first sector
		x++;
		if (p < 0)// the mid point is inside the circle
			p += 2 * x + 1;
		else
		{// the mid point is outside or at the circle
			y--;
			p += 2 * (x - y) + 1;
		}
		glBegin(GL_POINTS);
		glVertex2f(x1 + x, y1 + y);
		glVertex2f(x1 - x, y1 + y);
		glVertex2f(x1 + x, y1 - y);
		glVertex2f(x1 - x, y1 - y);
		glVertex2f(x1 + y, y1 + x);
		glVertex2f(x1 - y, y1 + x);
		glVertex2f(x1 + y, y1 - x);
		glVertex2f(x1 - y, y1 - x);
		glEnd();
	}
}
void translateCircle()
{
	int T[2] = { 50,10};

	midpointCircle();

	P[0] = P[0] + T[0];
	P[1] = P[1] + T[1];

	midpointCircle();
}
void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 0);
	translateCircle();
	glFlush();
}
int main(int argv, char** argc)
{
	glutInit(&argv, argc);
	glutInitWindowSize(1000, 1000);
	glutCreateWindow("window");
	gluOrtho2D(-300, 300, -300, 300);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}