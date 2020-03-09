with open("testfile.txt","w+") as file:
    file.write(input("Enter text"))

with open("testfile.txt","r") as file:
    n=int(input("Enter the number of lines to be printed: "))
    head= [next(file) for x in range(n)]

for i in range(len(head)):
    print(head[i])
