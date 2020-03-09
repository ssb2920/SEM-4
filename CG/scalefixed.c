#include<stdio.h> 
#include<math.h> 
#include<GL/glut.h>
#define max 10
int i, j;
void scale(float a[max][max], int n)
{
	float s[max];
	printf("\n Enter the sx and sy: ");
	scanf_s("%f%f", &s[0], &s[1]);
	for (i = 0; i < n; i++)
	{
		a[i][0] = a[i][0] * s[0];
		a[i][1] = a[i][1] * s[1];
	}
	glBegin(GL_LINE_LOOP);
	for (i = 0; i < n; i++)
	{
		glVertex2f(a[i][0], a[i][1]);
	}
	glEnd();

}
void translate(float a[max][max], int n)
{
	float T[max];
	printf("\n Enter the tx and ty: ");
	scanf_s("%f%f", &T[0], &T[1]);
	for (i = 0; i < n; i++)
	{
		a[i][0] = a[i][0] + T[0];
		a[i][1] = a[i][1] + T[1];
	}
	glBegin(GL_LINE_LOOP);
	for (i = 0; i < n; i++)
	{
		glVertex2f(a[i][0], a[i][1]);
	}
	glEnd();

}

void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 0);
	float a[max][max];
	int n;
	printf("Enter number of vertices\n");
	scanf_s("%d", &n);
	printf("\n Enter coordinates of vertices: ");
	for (i = 0; i < n; i++)
	{
		printf("\n Enter coordinates:");
		scanf_s("%f %f", &a[i][0], &a[i][1]);
	}
	glBegin(GL_LINE_LOOP);
	for (i = 0; i < n; i++)
	{
		glVertex2f(a[i][0], a[i][1]);
	}
	glEnd();
	translate(a, n);
	scale(a, n);
	translate(a, n);
	glFlush();
}

int main(int argv, char** argc)
{
	glutInit(&argv, argc);
	glutInitWindowSize(1000, 1000);
	glutCreateWindow("Scaling");
	gluOrtho2D(-300, 300, -300, 300);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}