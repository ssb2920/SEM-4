r=0
n=int(input("Enter page frame number\n"))
l=[None]*n
i=0
hit=0
miss=0
while (r!=-1):
    r=int(input("Enter page frame , -1 to stop\n"))
    if r==-1:
        break
    if r in l:
        l.remove(r)
        l.append(r)
        hit=hit+1
    else:
        l.pop(0)
        l.append(r)
        miss=miss+1
    ratio=hit*100/(hit+miss)
    print ("Hit ratio="+ str(ratio))
    print(*l,sep='\n')