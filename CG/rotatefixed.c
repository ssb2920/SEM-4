#include<stdio.h> 
#include<math.h> 
#include<GL/glut.h>
#define max 10
#define PI 3.14159
int i, j;
void rotate(double b[max][max],double a[max][max], int n)
{
	//double b[max][max];
	double deg, rad;
	printf("Enter angle of rotation in degrees :  ");
	scanf_s("%lf", &deg);
	rad = deg * (PI / 180);
		for (i = 0; i < n; i++)
		{
			b[i][0] = a[i][0] * cos(rad) -a[i][1] * sin(rad);
			b[i][1] = a[i][0] * sin(rad) + a[i][1] * cos(rad);
		}
		for (i = 0; i < n; i++)
		{
			a[i][0] = b[i][0];
			a[i][1] = b[i][1];
		}
	glBegin(GL_LINE_LOOP);
	for (i = 0; i < n; i++)
	{
		glVertex2f(b[i][0], b[i][1]);
	}
	glEnd();

}
void translate(double b[max][max],double a[max][max], int n)
{
	double T[max];
	//double b[max][max];
	printf("\n Enter the tx and ty: ");
	scanf_s("%lf%lf", &T[0], &T[1]);
	for (i = 0; i <n; i++)
	{
		b[i][0] = a[i][0] + T[0];
		b[i][1] = a[i][1] + T[1];
	}
	for (i = 0; i < n; i++)
	{
		a[i][0] = b[i][0];
		a[i][1] = b[i][1];
	}
	glBegin(GL_LINE_LOOP);
	for (i = 0; i <n; i++)
	{
		glVertex2f(b[i][0], b[i][1]);
	}
	glEnd();
	
}

void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 0);
	double a[max][max];
	double b[max][max] = { 0.0 };
	int n;
	printf("Enter number of vertices\n");
	scanf_s("%d", &n);
	printf("\n Enter coordinates of vertices: ");
	for (i = 0; i < n; i++)
	{
		printf("\n Enter coordinates:");
		scanf_s("%lf %lf", &a[i][0], &a[i][1]);
	}
	glBegin(GL_LINE_LOOP);
	for (i = 0; i < n; i++)
	{
		glVertex2f(a[i][0], a[i][1]);
	}
	glEnd();
	translate(b,a, n);
	rotate(b,a, n);
	translate(b,a, n);
	glFlush();
}

int main(int argv, char** argc)
{
	glutInit(&argv, argc);
	glutInitWindowSize(1000, 1000);
	glutCreateWindow("Rotation");
	gluOrtho2D(-300, 300, -300, 300);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}