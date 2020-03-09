#include<stdio.h> 
#include<math.h> 
#include<GL/glut.h>
#define SIN(x) sin(x * 3.141592653589/180) 
#define COS(x) cos(x * 3.141592653589/180) 
int r = 20;
int P[2] = { 100,100 };
int X[2] = { 50,50 };
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

void rotateCircle()
{
	int x = P[0], y = P[1], x_pivot = X[0], y_pivot = X[1];
	midpointCircle();
	int x_shifted = x - x_pivot;
	int y_shifted = y - y_pivot;
	int angle = 45;

	x = x_pivot + (x_shifted * COS(angle) - y_shifted * SIN(angle)); //xcos@-ysin@
	y = y_pivot + (x_shifted * SIN(angle) + y_shifted * COS(angle)); //xsin@+ycos@
	printf("New Center: (%f, %f) ", x, y);

	P[0] = x;
	P[1] = y;

	midpointCircle();
}

void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 0);
	rotateCircle();
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