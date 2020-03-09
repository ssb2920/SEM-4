#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>
void dda(float x1,float y1,float x2,float y2)
{
	glBegin(GL_POINTS);
	float dx, dy, steps, xi, yi, x, y;

	/*printf("Enter co-ordinates of first point\n");
	scanf_s("%f%f", &x1, &y1);
	printf("Enter co-ordinates of second point\n");
	scanf_s("%f%f", &x2, &y2);*/

	dx = x2 - x1;
	dy = y2 - y1;

	if (abs(dx) > abs(dy)) {
		steps = abs(dx);
	}
	else {
		steps = abs(dy);
	}

	xi = dx / steps;
	yi = dy / steps;
	x = x1;
	y = y1;
	glVertex2f(x, y);

	for (float i = 1; i < steps; i++) {
		x = x + xi;
		y = y + yi;
		glVertex2f(x, y);
	}
	glEnd();
}


void disp()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 0);
	dda(50,50,75,100);//Call function
	dda(75,100,100,50);
	dda(100,50,125,100);
	dda(125,100,150,50);
	dda(150,50,175,100);
	dda(175,100,200,50);
	glFlush();
}


int main(int argv, char** argc)
{
	glutInit(&argv, argc);
	glutInitWindowSize(800, 800);
	glutCreateWindow("window");
	gluOrtho2D(0, 300, 0, 300);
	glutDisplayFunc(disp);
	glutMainLoop();
	return 0;
}
