// Implements a dictionary's functionality
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>

#include "dictionary.h"

typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// number of "buckets"
const unsigned int N = 3;

node *hashtbl[N];

// counter for added words
int word_load = 0;

bool check(const char *word)
{
    int hashed = hash(word);

    // lecture 5 loop, loops through linked list
    for (node *tmp = hashtbl[hashed]; tmp != NULL; tmp = tmp->next)
    {
        if (strcasecmp(word, tmp->word) == 0)
        {
            return true;
        }
    }
    return false;
}

// turns letters to numbers using avicci 
unsigned int hash(const char *word)
{
    int invar = 26; 
    int first = (int)word[0];
    // for upercase letter
    if (first >= 65 && first <= 90)
    {
        invar = first - 65;
    }
    // for lowercase letters
    else if (first >= 97 && first <= 122)
    {
        
        invar = first - 97;
    }
    if (invar == 26)
    {
        return -1;
    }

    return invar;
}

bool load(const char *dictionary)
{
    // opens dictionary
    FILE *file = fopen(dictionary, "r");
    
    char buffvar[LENGTH + 1]; 
    
    // this loop was found on stackoverflow. It looks through the strings of the file
    while (fscanf(file, "%s", buffvar) != EOF)
    {
        node *new_node = malloc(sizeof(node));
        
        
        strcpy(new_node->word, buffvar);
        new_node->next = NULL;

        word_load++;

        int index = hash(buffvar);

        if (hashtbl[index] == NULL)
        {   
            hashtbl[index] = new_node;
            new_node->next = NULL;
        }

        else if (hashtbl[index] != NULL)
        {
            new_node->next = hashtbl[index];
            hashtbl[index] = new_node;
        }
    }
    fclose(file);

    return true;
}

// returns number of words that have been loaded from the file
unsigned int size(void)
{
    if (word_load > 0)
    {
        return word_load;
    }
    return 0;
}

// free's the dictionary that was loaded in 
bool unload(void)
{
    
    for (int i = 0; i < N; i++)
    {
        while (hashtbl[i] != NULL)
        {
            node *tmp = hashtbl[i]->next;
            free(hashtbl[i]);
            hashtbl[i] = tmp;
        }
        if (hashtbl[i] != NULL)
        {
            return false;
        }
    }
    return true;

}