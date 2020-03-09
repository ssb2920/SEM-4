#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>
void circle(int x1, int y1, int r)
{
	int x = 0;
	int y = r;
	int p = 1 - r;//5/4 is rounded to 1 for integer r

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
	// OPTIONAL:-> 1 of the circle
	glBegin(GL_POINTS);
	glEnd();
}
void disp()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 0);
	circle(50, 50, 100);
	circle(20, 75, 10);
	circle(80, 75, 10);
	circle(50,25,20);//Call function
	glFlush();
}


int main(int argv, char** argc)
{
	glutInit(&argv, argc);
	glutInitWindowSize(1000, 1000);
	glutCreateWindow("window");
	gluOrtho2D(-300, 300, -300, 300);
	glutDisplayFunc(disp);
	glutMainLoop();
	return 0;
}