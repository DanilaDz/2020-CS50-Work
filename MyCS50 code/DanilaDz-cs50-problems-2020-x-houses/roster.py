import sys
import csv
import cs50

# makes sure user uses 2 arguments
if len(sys.argv) != 2:
    print('usage: python roster.py (house name)')
    sys.exit(1)

db = cs50.SQL('sqlite:///students.db')

# takes all of the students info from the house that is but in as the argument
houselist = db.execute('SELECT * FROM students WHERE house = ? ORDER BY last, first', sys.argv[-1])

for row in houselist:
    
    # if there is no middle name
    if row['middle'] == None:
        print(row['first'] + ' ' + row['last'] + ',' + ' ' + 'born' + ' ' + str(row['birth']))
    
    # if there is one
    else:
        print(row['first'] + ' ' + row['middle'] + ' ' + row['last'] + ',' + ' ' + 'born' + ' ' + str(row['birth']))