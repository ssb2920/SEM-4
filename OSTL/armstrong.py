"""num=int(input('Enter number\n'))
n1=num
n2=0
while num>0:
	digit=num%10
	n2=n2+digit**3
	num=num//10
if n1==n2:
	print("Armstrong")
else:
	print("NOT")"""
num=int(input("Enter a number\n"))
n1=num
n2=0
while num>0:
	rem=num%10
	n2=n2+rem**3
	num=num//10
if n1==n2:
	print(n1," is an Armstrong number\n")
else:
	print("NOT")
