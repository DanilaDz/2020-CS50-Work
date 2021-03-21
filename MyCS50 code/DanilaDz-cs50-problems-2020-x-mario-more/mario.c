#include <stdio.h>
#include <cs50.h>
// main syntax
int main(void)
{
    // do while loop to keep asking user for correct input
    int n;
    do
    {
        n = get_int("Height: ");
    }    
    while (n < 1 || n > 8);
    // if and elif to print out the pyramid based on input
    if (n == 1)
    {
        printf("#  #\n");
    }
    // height = 2
    else if (n == 2)
    {
        printf(" #  #\n##  ##\n");
    }
    // height = 3
    else if (n == 3)
    {
        printf("#  #\n##  ##\n###  ###\n");
    }
    // height = 4
    else if (n == 4)
    {
        printf("#  #\n##  ##\n###  ###\n####  ####\n");
    }
    // height = 5
    else if (n == 5)
    {
        printf("#  #\n##  ##\n###  ###\n####  ####\n#####  #####\n");
    }
    // height = 6
    else if (n == 6)
    {
        printf("#  #\n##  ##\n###  ###\n####  ####\n#####  #####\n######  ######\n");
    }
    // height = 7
    else if (n == 7)
    {
        printf("#  #\n##  ##\n###  ###\n####  ####\n#####  #####\n######  ######\n#######  #######\n");
    }
    // height = 8
    else if (n == 8)
    {
        printf("       #  #\n      ##  ##\n     ###  ###\n    ####  ####\n   #####  #####\n  ######  ######\n #######  #######\n########  ########\n");
    }
    
}