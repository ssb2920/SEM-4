def firstFit(blockSize, m, processSize, n):                    # Function to allocate memory to blocks as per First fit algorithm  
	allocation = [-1] * n                                      # Stores block id of the block allocated to a process 
	for i in range(n):                                         # pick each process and find suitable blocks according to its size and assign to it 
		for j in range(m): 
			if blockSize[j] >= processSize[i]: 				
				allocation[i] = j                              # allocate block j to p[i] process  
				blockSize[j] -= processSize[i]                 # Reduce available memory in this block.
				break

	print(" Process No.  Process Size	 Block no.") 
	for i in range(n): 
		print(" ", i + 1, "     	 ", processSize[i], "	        ", end = "   ") 
		if allocation[i] != -1: 
			print(allocation[i] + 1) 
		else: 
			print("Not Allocated") 

# Driver code 
#if __name__ == '__main__': 
#blockSize = [100, 500, 200, 300, 600]

processSize = [212, 417, 112, 426] 
m = len(blockSize) 
n = len(processSize) 
firstFit(blockSize, m, processSize, n) 

"""
 Process No.  Process Size       Block no.
  1               212              2
  2               417              5
  3               112              2
  4               426              Not Allocated
"""