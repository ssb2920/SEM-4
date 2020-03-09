def worstFit(blockSize, m, processSize, n):               # Function to allocate memory to blocks as per worst fit algorithm 
	allocation = [-1] * n                                 # Stores block id of the block allocated to a process
	for i in range(n):                                    # pick each process and find suitable blocks according to its size ad assign to it 
		wstIdx = -1                                       # Find the best fit block for current process 
		for j in range(m): 
			if blockSize[j] >= processSize[i]: 
				if wstIdx == -1: 
					wstIdx = j 
				elif blockSize[wstIdx] < blockSize[j]: 
					wstIdx = j 
		if wstIdx != -1:                                  # If we could find a block for current process 
			allocation[i] = wstIdx                        # allocate block j to p[i] process
			blockSize[wstIdx] -= processSize[i]           # Reduce available memory in this block. 

	print("Process No.  Process Size   Block no.") 
	for i in range(n): 
		print(i + 1, "	     ", processSize[i], end = "            ") 
		if allocation[i] != -1: 
			print(allocation[i] + 1) 
		else: 
			print("Not Allocated") 

# Driver code 
if __name__ == '__main__': 
	blockSize = [100, 500, 200, 300, 600] 
	processSize = [212, 417, 112, 426] 
	m = len(blockSize) 
	n = len(processSize) 
	worstFit(blockSize, m, processSize, n) 

"""
Process No.  Process Size   Block no.
1             212            5
2             417            2
3             112            5
4             426            Not Allocated
"""
