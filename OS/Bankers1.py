P = 5                                                # Number of processes
R = 3                                                # Number of resources

def calculateNeed(need, max, allot):                 # Function to find the need of each process 
	for i in range(P): 
		for j in range(R): 
			need[i][j] = max[i][j] - allot[i][j]     # Need of instance = max instance - allocated instance

def isSafe(processes, avail, max, allot):            # Function to find the system is in safe state or not  
	need = [] 
	for i in range(P): 
		l = [] 
		for j in range(R): 
			l.append(0) 
		need.append(l) 
		
	calculateNeed(need, max, allot)                   # Function to calculate need matrix   
	finish = [0] * P                                  # Mark all processes as infinish
	safeSeq = [0] * P                                 # To store safe sequence 
	work = [0] * R                                    # Make a copy of available resources 
	for i in range(R): 
		work[i] = avail[i] 

	count = 0                                         # While all processes are not finished or system is not in safe state. 
	while (count < P):  
		found = False                                 # Find a process which is not finish and whose needs can be satisfied with current work[] resources.
		for p in range(P): 
			if (finish[p] == 0):                      # First check if a process is finished, if no, go for next condition                   
				for j in range(R):                    # Check if for all resources of current P need is less than work 
					if (need[p][j] > work[j]): 
						break

				if (j == R - 1):                      # If all needs of p were satisfied.  
					for k in range(R):                # Add the allocated resources of current P to the available/work resources i.e.free the resources 
						work[k] += allot[p][k] 

					safeSeq[count] = p                # Add this process to safe sequence.  
					count += 1
					finish[p] = 1                     # Mark this p as finished 
					found = True
				
		if (found == False):                          # If we could not find a next process in safe sequence. 
			print("System is not in safe state") 
			return False
    # If system is in safe state then safe sequence will be as below
	print("System is in safe state.", "\nSafe sequence is: ", end = " ")  
	print(*safeSeq) 

	return True

# Driver code 
if __name__ =="__main__": 
	
	processes = [0, 1, 2, 3, 4]  
	avail = [3, 3, 2]                                                # Available instances of resources
	max = [[7, 5, 3], [3, 2, 2], [9, 0, 2], [2, 2, 2], [4, 3, 3]]    # Maximum R that can be allocated to processes 
	allot = [[0, 1, 0], [2, 0, 0], [3, 0, 2], [2, 1, 1], [0, 0, 2]]  # Resources allocated to processes  
	isSafe(processes, avail, max, allot)                             # Check system is in safe state or not

"""
System is in safe state.
Safe sequence is:  1 3 4 0 2
"""