# I used some examples from cash in C
from cs50 import get_float
import math


def main():
    
    # keeps prompting user for input
    while True:
        change = get_float('Change owed: ')
        cents = round(change * 100)
        if change > 0: 
            break
    
    # does all the math to get the remainder coins
    # the double slash removes the float part of the number and leaves the integer
    quarters = cents // 25
    dimes = (cents % 25) // 10
    nickels = ((cents % 25) % 10) // 5
    pennies = ((cents % 25) % 10) % 5
    
    # adds all coins together and prints them
    print(quarters + dimes + nickels + pennies)
    
main()
