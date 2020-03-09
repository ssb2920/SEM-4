#include<stdio.h> 
#include<math.h> 
#include<GL/glut.h>
float P[2] = { 100,100 };
float R[2] = { 50,25 };

void midpointEllipse()
{
	glBegin(GL_POINTS);
	float rx, ry, xc, yc, p1, p2, x, y;
	rx = R[0];
	ry = R[1];
	xc = P[0];
	yc = P[1];
	x = 0;
	y = ry;
	p1 = ry * ry - rx * rx * ry + 0.25 * rx * rx;
	while (2 * ry * ry * x < 2 * rx * rx * y)
	{
		glVertex2f(xc + x, yc + y);
		glVertex2f(xc + x, yc - y);
		glVertex2f(xc - x, yc - y);
		glVertex2f(xc - x, yc + y);
		if (p1 < 0)
		{
			x = x + 1;
			p1 = p1 + ry * ry + 2 * ry * ry * x;
		}
		else {
			x = x + 1;
			y = y - 1;
			p1 = p1 + 2 * ry * ry * x - 2 * rx * rx * y + ry * ry;
		}
	}
	p2 = ((x + 0.5) * (x + 0.5) * ry * ry) + ((y - 1) * (y - 1) * rx * rx) - (rx * ry * rx * ry);
	while (y > 0)
	{
		glVertex2f(xc + x, yc + y);
		glVertex2f(xc + x, yc - y);
		glVertex2f(xc - x, yc - y);
		glVertex2f(xc - x, yc + y);
		if (p2 > 0)
		{
			y = y - 1;
			p2 = p2 + rx * rx - 2 * rx * rx * y;
		}
		else
		{
			x = x + 1;
			y = y - 1;
			p2 = p2 + 2 * ry * ry * x - 2 * rx * rx * y + rx * rx;
		}
	}

	glEnd();
}
void translateEllipse()
{
	int T[2] = { -100,-100 };

	midpointEllipse();

	P[0] = P[0] + T[0];
	P[1] = P[1] + T[1];

	midpointEllipse();
}
void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 0);
	translateEllipse();
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