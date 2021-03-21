#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

int main(void)
{
    // input
    string input = get_string("Text: ");
    int letters = 0;
    int words = 1;
    int sentences = 0;
    // counts words
    for (int spaces = 0; spaces < strlen(input); spaces++)
    {
        if (input[spaces] == ' ')
        {
            words++;
        }
    }
// counts letters
    for (int letter = 0; letter < strlen(input); letter++)
    {
        if (tolower(input[letter]) >= 'a' && tolower(input[letter]) <= 'z')
        {
            letters++;  
        }
            
    }
    // counts sentences
    for (int sent = 0; sent < strlen(input); sent++)
    {
        if (input[sent] == '.' || input[sent] == '!' || input[sent] == '?')
        {
            sentences++;
        }
    }
    // avarages the amount of letters and sentences per 100 words
    float L = (letters / ((float) words)) * 100;
    float S = (sentences / ((float) words)) * 100;
    int liau_index = round(0.0588 * L - 0.296 * S - 15.8);
    
    // prints out the answer
    if (liau_index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (liau_index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", liau_index);
    }
    
}
