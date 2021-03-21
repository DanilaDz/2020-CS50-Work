#include <stdio.h>
#include <math.h>
#include <cs50.h>


int main()
{
    int cents;
    // keeps asking the user to input a valid number
    do
    {
        float change = get_float("Change owed: ");
        cents = round(change * 100);
    }
    while (cents <= 0);
    
    // finds out how many of each coin is needed to the total
    int quarters = cents / 25;
    int dimes = (cents % 25) / 10;
    int nickels = ((cents % 25) % 10) / 5;
    int pennies = ((cents % 25) % 10) % 5;
    // prints answer
    printf("%d\n", quarters + dimes + nickels + pennies);
}