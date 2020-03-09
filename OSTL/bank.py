accclist=[]
class Account:
    balance=500.0
    rate=0.07
    count=1000
    def createAccount(self):
        self.name=str(input("enter your name"))
        self.address=str(input("enter ther address"))
        self.contact=int(input("enter your contact number"))
        Account.count=Account.count+1
        self.accno=Account.count
        
    def computeInterest(self):
        return self.balance*self.rate
    
    def deposit(self):
        add=int(input("enter the amount to be deposited:"))
        self.balance=self.balance+Account.computeInterest(self)+add
        print(f"Account blanace:{self.balance}")
    
    def withdraw(self):
        sub=int(input("enter the amount to be deposited"))
        if self.balance-sub <0:
            print("amount cannot be withdrawn")
        else:
            self.balance=self.balance-sub
            print(f"Account blanace:{self.balance}")
    def __str__(self):
        return(f"-----Account Details-----\nAccount number: {self.accno}\nAccount name: {self.name}\nBalance: {self.balance}")
        
def menu(Acc):
    while(True):
        print(f"-------welcome {Acc.name}-----")
        print("1.deposit")
        print("2.withdraw")
        print("3.show details")
        print("4.return")
        choice=int(input("Enter:"))
        
        if choice==1:
            Acc.deposit()
        elif choice==2:
            Acc.withdraw()
        elif choice==3:
            print(Acc)
        elif choice==4:
            break
        else:
            print("wrong choice")
while True:
    print("1.create new Account")
    print("2.show all account" )
    print("3.Exit")
    ch=int(input("enter the choice"))
    if(ch==1):
        new=Account()
        new.createAccount()
        menu(new)
        acclist.append(new)
    elif ch==2:
        print("list of accounts")
        if(acclist):
            for accounts in acclist:
                print(accounts.accno)
                acc=None
            accno=int(input("enter the account no to be accessed"))
            for accounts in acclist:
                if(accno==accounts.accno):
                    acc=accounts
                if(acc==None):
                    print("Account not found")
                else:
                    menu(acc)
        else:
            print("no accounts added")
    elif ch==3:
        print("thsnkyou for visiting")
    else:
        print("wrong choice")
