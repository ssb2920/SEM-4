import sys
n=int(input("enter no. of items"))
list=[]
for i in range(n):
	list.append(int(input("Enter element")))
print("b4 sorting\n",list)
for i in range(n-1):
	for j in range(n-i-1):
		if(list[j]>list[j+1]):
			temp=list[j]
			list[j]=list[j+1]
			list[j+1]=temp
			
print("after sorting\n",list)