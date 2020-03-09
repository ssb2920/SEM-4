import math
print("Enter a,b,c\n")
a=int(input())
b=int(input())
c=int(input())
d=b**2-4*a*c
if d>=0:
	r1=(-b+math.sqrt(d))/(2*a)
	r2=(-b-math.sqrt(d))/(2*a)
	print("The solutions are",r1,"and",r2)
else:
	print("No Real Solutions")