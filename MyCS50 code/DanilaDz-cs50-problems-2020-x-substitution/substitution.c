#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    // makes sure that you have 2 arguments
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY\n");// how to use the program
        return 1;
    }
    
    // checks for 26 letters

    if (strlen(argv[1]) != 26)
    {
        printf("Your key needs to be 26 letters!\n");
        
        return 1;
    }
    
    // checks to know it is a letter   
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isalpha(argv[1][i]) == false) // function isalpha allows you to detect whether or not its a letter
        {
            printf("You need to use alphabetic characters!\n");
            return 1;
        }
    }
        
    // looks for repeated characters
    char conv[2][26];
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        conv[0][i] = 'A' + i; 
        conv[1][i] = argv[1][i];
    }
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        int j = 0;
        for (int k = 0; k < strlen(argv[1]); k++)
        {
            if (toupper(conv[1][k]) == toupper(conv[1][i]))
            {
                j++;                  
                if (j == 2)
                {
                    printf("You can't have repeated characters!\n");
                    return 1;
                }
            }
        }
    }
        
    
    //cyphering
    // the text
    string plain = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int i = 0, j = strlen(plain); i < j; i++)
    {
        if (isalpha(plain[i]))
        {  
            if (islower(plain[i])) //looks at lowercase
            {
                for (int var = 0; var < strlen(argv[1]); var++)
                {
                    if (tolower(conv[0][var]) == plain[i])  //keeps lower text to lower
                    {   
                        printf("%c", tolower(conv[1][var]));
                    }
                }
            }
            if (isupper(plain[i])) //looks at uppercase
            {
                for (int var = 0; var < strlen(argv[1]); var++)
                {
                    if (toupper(conv[0][var]) == plain[i]) // keeps upper text to upper
                    {   
                        printf("%c", toupper(conv[1][var]));
                    }
                }
            }
        }
        else
        {
            printf("%c", plain[i]);
        }
    }
    printf("\n");
    return 0;
    










}