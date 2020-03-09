import csv
csvfile=open("test.csv","r")
data=csv.reader(csvfile)

def wordread(data):
	for i in range(len(data.Name)):
		if data.Name[i][0] == "a" or data.Name[i][0] == "A":
			print(data.Name[i])

wordread(data)
     
