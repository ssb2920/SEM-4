M=[]
Al=[]
N=[]
Av=[]
F=[]
req=[]
n=int(input("Enter the no. of processes :"))
m=int(input("Enter the no. of resources :"))
def disp(b,s):
    print("The {} matrix:".format(s))
    if (isinstance(b[0],int)) or (isinstance(b[0],str)) :
            for row in b:
                    print(row,end=" ")
            print()
    else:
            for row in range(len(b)):
                    print(b[row])
def create(b,s):
    print("The {} matrix:".format(s))
    b=[[0 for i in range(m)]for i in range(n)]
    for i in range(0,n):            #no. of process
        for j in range(0,m):        #no. of resources
            b[i][j]=int(input("Enter the"+str(i)+"th process's "+str(j)+"th resource element:"))  #Rj resource of Pi process
    disp(b,s)
    return b

def check(a,b):
        for i in range(m):
                if a[i]>b[i] :
                        return 0
        return 1
def safe():
        j=i=k=flag=0
        q=[]
        while F.count('F')!=0 :
                print("i={}".format(i))
                if (F[i]=='F') and (check(N[i],Av[k])) :
                        j=0
                        F[i]='T'
                        q.append(i)
                        for j in range(m):
                                Av[k+1][j]=Av[k][j]+Al[i][j]
                        k+=1
                if j>n :
                        print("The system is in deadlock.")
                        flag=1
                        break
                disp(F,"Finish")
                disp(Av[0],"Input Available")
                print("process    Allocation     Max      Available     Need")
                for r in range(4):
                        print(end='   ')
                        for s in range(m):
                                print("{}".format(chr(ord('A')+s)),end='  ')
                print()
                for row in range(n):
                    print('P{}'.format(row),Al[row],M[row],Av[row+1],N[row],sep='       ')
                j+=1
                i=(i+1)%n
        if flag==0:
                print('The process sequence is:')
                for i in range(len(q)):
                        if i==len(q)-1:
                                print(q[i])
                        else:
                                print(q[i],end='->')
def res_alloc(a):
        k=int(input("Enter the process request:"))
        for i in range(m):                                              #creating finish and available matrix
                req.append(int(input("Enter the {} th Resource in request: ".format(str(chr(ord('A')+i))))))
        disp(req,"request")
        disp(N[k]," process {}'s Need ".format(k))
        disp(Av[a],"input available")
        if check(req,N[k])!=1 :
                print("The request is deninied becuse it will cause deadlock.")
                return
        if check(req,Av[a])!=1 :
                print("The process request must wait a while try later")
                return
        for i in range(m):
                Av[a][i]-=req[i]
                N[k][i]-=req[i]
                Al[k][i]+=req[i]
        safe()
M=create(M,'Max')
Al=create(Al,'Allocation')
Av=[[0 for i in range(m) ]for i in range(n+1)]
F=['F' for i in range(n)]
for i in range(m):                                #creating finish and available matrix
        Av[0][i]=int(input("Enter the {} th Resource available: ".format(str(chr(ord('A')+i)))))
N=[[0 for i in range(m) ]for i in range(n)]
for i in range(n):
        for j in range(m):
                N[i][j]=M[i][j]-Al[i][j]                        #creating need matrix
disp(N,"Need")
disp(F,"Finish")
disp(Av[0],"Available")
c=1
while c==1:
        s=int(input("Enter \n1. Safety Algorithm \n2. Resource Request Algorithm :  "))
        if s==1:
                safe()
        elif s==2:
                res_alloc(0)
        else:
                print("wrong option")
        c=int(input("enter zero to end"))