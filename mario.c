/*
 * mario.c
 *
 * CS50; Problem Set 1
 * Jeevan B S
 *
 * Constructs a Pyramid no greater than 23 rows high
 * using Hashes(#)
 */

#include <stdio.h>
#include <cs50.h>

// Function prototype declaration
void blankspace(int);
void hashes(int);

// Make 'height' a global variable so that the functions
// can also make use of it
int height;

int main(void)
{
    // Use Boolean type number to repeat loop
    _Bool loopBreak = 1;

    // Repeat loop till proper number is input
    while(loopBreak)
    {
        // Get 'height' of the Pyramid
        printf("Height of the Pyramid: ");
        height = GetInt();
        // Check if height <= 23 AND != negative number AND !> 23
        if ((height <= 23) && (height >= 0))
            loopBreak = 0;
        else
            loopBreak = 1;
     }
     
     // Count represents the number of '#s' to be output
     // Since the minimum number of #s in a row is 2, initialise count to 2
     int count = 2;
     // Repeat loop to fulfill the height of the Pyramid
     for (int i = 0; i < height; i++)
     {
        // Outputs WhiteSpaces
        blankspace(count);
        // Outputs Hashes (#s)
        hashes(count);
        // Separates one row from the other
        printf("\n");
        // Increase count after every loop
        count++;
      }
      return 0;
}

/*
 * Function to output 'cnt' number of '#s'(Hashes)
 */
void hashes(int cnt)
{
    // Output 'cnt' #s    
    for (int i = 0; i < cnt; i++)
    {
        printf("#");
    }
}

/*
 * Function to output 'height + 1 - cnt' number of 'WhiteSpaces'
 */
void blankspace(int cnt)
{
   // Variable 'WhiteSpace' contains 32 stored in it
   // 32 is the decimal notation for WhiteSpaces
   char whiteSpace = ' ';
   // Loop to printout whitespaces
   for (int i = 0; i < height + 1 - cnt; i++)
   {
        printf("%c", whiteSpace);
   }
}
