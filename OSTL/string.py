text=input("Enter a string\n")
vowels=0
consonants=0
spaces=0
for i in text.lower():
	if i=="a" or i=="e" or i=="i" or i=="o" or i=="u":
		vowels+=1
	elif i==" ":
		spaces+=1
	else:
		consonants+=1
print("vowels= ",vowels,"\nconsonants= ",consonants,"\nSpaces= ",spaces)