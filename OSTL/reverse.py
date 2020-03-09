def reverse(input):
	inpw = input.split(" ")
	inpw = inpw[::-1]
	print(inpw)
	output =' '.join(inpw)
	return output


f= open("testfile.txt","r")
input = str(f.read())
print(reverse(input))
f.close()
