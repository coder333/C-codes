/*
 * caesar.c
 *
 * CS50; Problem Set 2
 * Jeevan B S
 *
 * Program to Encrypt Plain Text using Caesar Cipher
 */

#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Contains English alphabets in Upper case
char upper[27];
// Contains English alphabets in lower case
char lower[27];

// Function prototypes
char convert(char);
char addKeyU(char);
char addKeyL(char);


// Store 'key' in variable 'k' as global variable
// (Functions also make use of the key)
int k;

int main(int argc, char* argv[])
{
    // Run program only if the command line arguments are correct
    if (argc == 2)
    {
        // Convert 'key' stored as a string to an integer
        k = atoi(argv[1]);
    }
    else
    {
        // Indicate correct usage to the user
        printf("Usage: ./caesar <Key>\n");
        return 1;
    }
    // Exit program if the key is a negative number 
    if (k < 0)
    {
        printf("You input an invalid Key\n");
        return 1;
    }
    
    // Convert 'k' to a value between 1 and 26
    k = k % 26;

    // Store upper case alphabets in the array 'upper[]'
    for (int i = 0, n = 65; i < 26; i++, n++)
        upper[i] = n;
    upper[26] = '\0';
    
    // Store lower case alphabets in the array 'lower[]'
    for (int i = 0, n = 97; i < 26; i++, n++)
        lower[i] = n;
    lower[26] = '\0';
    
    // string 'plainText' contains input text
    string plainText;
    plainText = GetString();
    
    // array of characters 'cipherText[]' contains output text 
    char cipherText[100];
    int l;
    
    // Converts the Plain Text into Cipher Text
    for (int i = 0, len = strlen(plainText); i < len; i++)
    {
        // Call function 'char convert(char)'
        cipherText[i] = convert(plainText[i]);   
        l = i;
    }    
    cipherText[l+1] = '\0';
    
    // Output Cipher Text
    for (int i = 0; cipherText[i] != '\0'; i++)
        printf("%c", cipherText[i]);
   
    printf("\n");    
    // Exit normally
    return 0;
}

/*
 * Function to convert Plain Text into Cipher Text
 */
char convert(char p)
{
    // Contains one cipher character
    char c;
    // Check if the character is an alphabet
    if (isalpha(p))
    {
        // Check if the character is an Upper alphabet
        if (isupper(p))
        {
           // Call a function to add 'key' to the 'alphabet'
           c = addKeyU(p);
           return c;
        }
        // If the character is not an Upper alphabet then it 
        // should be a lower alphabet
        else
        {
            // Call a function to add 'key' to the 'alphabet'
            c = addKeyL(p);
            return c;
        }
    }
    // If the character is not an alphabet, then return character as it is
    else
        return p;
}

/*
 * Function to Add 'Key' to the 'Upper alphabet'
 */
char addKeyU(char p)
{
    // Contains cipher character
    char c;
    // Variable to navigate array 'upper[]'
    int j;
    // Find out where 'p' lies within array 'upper[]'
    for (int i = 0; i < 26; i++)
    {
        // Get the place where 'p' is and store it in 'j'
        if (upper[i] == p)
            j = i;
    }
    // Copy actual key
    int k1 = k + 1;
    // Go around the array upper[] till the key reaches 0
    while (k1 != 0)
    {
        c = upper[j];
        k1--;
        j++;
        if (j == 26)
            j = 0;
    }
    return c;
        
}

/*
 * Function to Add key to the lower alphabet
 */
char addKeyL(char p)
{
    char c;
    // Variable to navigate lower[]
    int j;
    // Get where alphabet 'p' is within the array
    for (int i = 0; i < 26; i++)
    {
        if (lower[i] == p)
            j = i;
    }
    int k1 = k + 1;
    // Go around the array lower[] till key reaches 0
    while (k1 != 0)
    {
        c = lower[j];
        k1--;
        j++;
        if (j == 26)
            j = 0;
    }
    return c;
}
