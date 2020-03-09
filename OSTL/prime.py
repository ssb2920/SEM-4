for num in range(0,100):
	if num>1:
		for j in range(2,num):
			if(num%j==0):
				break
		else:
			print(num)