#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define block 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // makes sure you are using it correctly
    if (argc != 2)
    {
        printf("Usage: recover image\n");
        return 1;
    }

    // opens file of the user (in this case, CS50)
    FILE *file = fopen(argv[1], "r");

    BYTE buffer[512];
    
    int jpegs = 0;

    char namefile[8];
    
    FILE *nullfile = NULL;

    while (true)
    {
        //reads a block of 512 bytes
        int readfiles = fread(buffer, sizeof(BYTE), block, file);

        // stops looking through jpeg at the end 
        if (readfiles == 0 && feof(file))
        {
            break;
        }
        
        //checks for jpeg and makes the jpeg counter go up
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0 && nullfile != NULL)
        {
            fclose(nullfile);
            jpegs++;
        }

        //checks for jpeg and opens a file for writing (I was struggling here so I asked google for help)
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            sprintf(namefile, "%03i.jpg", jpegs);
            nullfile = fopen(namefile, "w");
        }

        if (nullfile != NULL)
        {
            fwrite(buffer, sizeof(BYTE), readfiles, nullfile);
        }
    }

    // closes all the open files
    fclose(nullfile);

    fclose(file);

    return 0;
}