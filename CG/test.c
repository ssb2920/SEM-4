
#include <stdio.h>
#include <math.h>

#define PI 3.14159
int main()
{
  double sinValue, radianVal, degreeVal;
  printf(" Please Enter an Angle in degrees :  ");
  scanf("%lf", &degreeVal);
  
  // Convert Degree Value to Radian 
  radianVal = degreeVal * (PI/180)
  sinValue = cos(radianVal);
  
  printf("\n The Sine value of %f = %f ", degreeVal, sinValue);
  
 }