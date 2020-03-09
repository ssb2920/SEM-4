class Node:
    def __init__(self):
        self.data = 0
        self.pri = 10
        self.next = None
    def enque(self, start):
        self.data = int(input("Enter value to be enqueued: "))
        self.pri = int(input("Set priority (Low Value -> High Priority): "))
        ptr = start
        preptr = ptr
        if(start == None):
            start = self
        elif(start.pri > self.pri):
            self.next = start
            start = self
        else:
            while(ptr.next != None and ptr.next.pri <= self.pri):
                preptr = ptr
                ptr = ptr.next

            self.next = ptr.next
            ptr.next = self

        return start

    def deque(self, start):
        if(start == None):
            print("List empty")
        else:
            print(f"Dequeued data: {start.data}")
            start = start.next
        return start

    def disp(self, start):
        ptr = start
        print("Elements in the queue are")
        if(start == None):
            print("List empty")
        else:
            while(ptr != None):
                print(f"{ptr.data}", end = ' ')
                ptr = ptr.next
            print(" ")

a = Node()
b = Node()
c = Node()
d = Node()
e = Node()
f = Node()
start = None
start = a.enque(start)
start = b.enque(start)
start = c.enque(start)
start = d.enque(start)
start = e.enque(start)
start = f.enque(start)
start.disp(start)
start = start.deque(start)
start = start.deque(start)
start = start.deque(start)
start.disp(start)
