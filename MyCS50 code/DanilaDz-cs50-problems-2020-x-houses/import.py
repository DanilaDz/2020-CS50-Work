import sys
import csv
import cs50

# checks for correct number of arguments
if len(sys.argv) != 2:
    print('usage: python import.py characters.csv')
    sys.exit(1)

db = cs50.SQL('sqlite:///students.db')

# opens character file
with open(sys.argv[-1], 'r') as character_file:
    
    # creates reader
    reader = csv.DictReader(character_file)
    
    for row in reader:
        
        # makes a type of list using the function split so that the names of the people are split into first name as a seperate value and so is the last name and middle name if they have one
        namelist = row['name'].split()
        
        # the if statements check to see if the name list above has 2 values, which means they have a first and last name, or 3, which means first, last, and middle
        if len(namelist) == 2:
            fname = namelist[0]
            lname = namelist[1]
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", fname, None, lname, row['house'], row['birth'])
            
        elif len(namelist) == 3:
            fname = namelist[0]
            mname = namelist[1]
            lname = namelist[2]
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", fname, mname, lname, row['house'], row['birth'])