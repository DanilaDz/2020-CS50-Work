import csv
from sys import argv, exit

# checks to make sure you put the correct number of argv's
if len(argv) != 3:
    print('Make sure to do : python dna.py data.csv sequence.txt')
    exit(1)

# opens datatable file and saves it as a list
with open(argv[1], 'r') as filecsv:
    reader = csv.reader(filecsv)
    csvfi = list(reader)

# opens sequence file and saves it as a list
with open(argv[2], 'r') as filesequence:
    reader = csv.reader(filesequence)
    seq = list(reader)

# sets variables
counter = 0
hold = 0
keycsv = csvfi[0][1:]
seq2 = seq[0][0]
openlis = []

# loop to iterate through str's
for i in range(len(keycsv)):
    arr = []
    counter = 0
    hold = 0
    # loop through sequence
    while hold < len(seq2):

        if (seq2[hold:hold+len(keycsv[i])]) == (keycsv[i]):
            counter += 1
            hold += len(keycsv[i])

        else:
            if counter > 0:
                arr.append(counter)
            counter = 0
            hold += 1
    # if list cointains something sort the array
    if len(arr) > 0:
        arr.sort()
        openlis.append(arr[-1])

numrows = len(csvfi)

for i in range(1, numrows):

    keycsv2 = list(map(int, csvfi[i][1:]))
    # compare the final list with the new list
    if openlis == keycsv2:
        print(csvfi[i][0])
        exit(0)

print("No match")
    
