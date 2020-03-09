#PQueue
'''def _init_(self):
    self.next=None
    self.val=0
    self.pri=10
def enqueue(self,start):
    self.pri=int(input("Enter priority\n"))
    self.val=int(input("Enter val\n"))
    ptr=start
    preptr=ptr
    if start==None:
        start=self
    elif(start.pri>self.pri):
        self.next=start
        start=self
    else:
        while(ptr.next!=None and ptr.next.pri<=self.pri):
            preptr=ptr
            ptr=ptr.next
        self.next=ptr.next
        ptr.next=self
    return start
def deque(self,start):
    if(start==None):
        print("Queue is empty")
    else:
        print(start.val)
        start=start.next'''
#write display here
class Node:        
    def _init_(self):
        self.next=None
        self.data=0
    def push(self,start):
        self.data=int(input("Enter data \n"))
        if start==None:
            start=self
        else:
            self.next=start
            start=self
        return start
    def pop(self,start):
        if start==None:
            print("Stack empty")
            return start
        else:
            start=self.next
            self.next=None
            return start
    def display(self,start):
        ptr=start
        while(ptr!=None):
            print(ptr.data)
            print("\n")
            ptr=ptr.next
a=Node()
b=Node()
c=Node()
d=Node()
start=None
start=a.push(start)
start=b.push(start)
start.display(start)
start=start.pop(start)
start=c.push(start)
start=start.pop(start)