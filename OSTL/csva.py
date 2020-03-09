import csv
csvfile=open("test.csv","r")
csvreader=csv.reader(csvfile)
for row in csvreader:
	print(row[1])
csvfile.close()