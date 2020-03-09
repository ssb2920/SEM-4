#bankers
allo=[]
maxm=[]
need=[]
ava=[]
r=int(input("Enter no of resources"))
p=int(input("Enter no of processes"))
comp=[False]*p
#allocation
print("For allocation \n")
for i in range(p):
    process=[]
    print("For process ",i+1)
    for j in range(r):
        process.append(int(input(f"Enter inst for resource {j+1} ")))
    allo.append(process)
print("For maximum \n")
for i in range(p):
    process=[]
    print("For process ",i+1)
    for j in range(r):
        process.append(int(input(f"Enter max inst for resource {j+1} ")))
    maxm.append(process)
for i in range(p):
    process=[]
    for j in range(r):
        process.append(maxm[i][j]-allo[i][j])
    need.append(process)
for i in range(r):
    ava.append(int(input(f"Enter available inst for resource {j+1} ")))

print(need) 
#safety
flag=0
while(not flag):
    for i in range(p):
        check=0
        flag=1
        if(not comp[i]):
            flag=0
            for j in range(r):
                if (need[i][j]<=ava[j]):
                    check=True
                else:
                    check=False
                    break
        if(check):
            comp[i]=True
            for j in range(r):
                ava[j]=ava[j]+allo[i][j]
            print(ava)
            print(f"Process {i+1}")