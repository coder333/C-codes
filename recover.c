/****************************************************************************
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 ***************************************************************************/
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <stdint.h>
 
typedef uint8_t  BYTE;
typedef uint32_t DWORD;
typedef int32_t  LONG;
typedef uint16_t WORD;

// Recover Four Bytes of Data from 'card.raw'
typedef struct
{
    BYTE one;
    BYTE two;
    BYTE three;
    BYTE four;
}firstFour;

int main(int argc, char *argv[])
{
    // Separate pointers pointing at the input and the output files
    FILE *inptr, *outptr;
    // Input pointer pointing at card.raw
    inptr = fopen("card.raw", "r");
    
    // Writes Data when 'write = 1'
    _Bool write = 0;
    // 'flag' is of Data Type 'firstFour'
    firstFour flag;
    // For naming jpgs
    char buffer[50]; int count = 000;
    // i = 1052160 is the number of times the loop should be executed to get all 51 images
    // i = 1052160 arrived at from looking at 'card.txt' obtained from 'card.raw'
    for (long int i = 0; i < 1052160; i++)
    {
        fread(&flag, sizeof(firstFour), 1, inptr);
        if ( (flag.one == 0xff) && (flag.two == 0xd8) && (flag.three == 0xff) && ((flag.four == 0xe0) || (flag.four == 0xe1)) ) 
        {
                write = 1;
                // A convenient way of getting the appropriate names for the jpegs
                if (count < 10)
                    sprintf(buffer, "00%d.jpg", count);
                else
                    sprintf(buffer, "0%d.jpg", count);
                    
                if ((count > 0) && (count < 50))
                    // Close pointer pointing at the previous jpeg
                    fclose(outptr);
                outptr = fopen(buffer, "w");
                count++;
        }
            
        if (write == 1)    
            fwrite(&flag, sizeof(firstFour), 1, outptr);
    }
    
    fclose(inptr);
    fclose(outptr);
    
    return 0;
}
