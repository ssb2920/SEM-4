import sys
n=int(input("enter no. of items"))
list=[]
for i in range(n):
	list.append(int(input("Enter element")))
m=int(input("enter element to be found"))
for i in range(n):
	if (m==list[i]):
		print("element found at loc ",i+1)
		sys.exit()
print("Not found")