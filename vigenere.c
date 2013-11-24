/*
 * vigenere.c
 *
 * CS50; Problem Set 2
 * Jeevan B S
 *
 * Encrypts Plain Text using vigenere cipher
 */

#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

// Prototype declaration
char getkey(int);
char convert(char, char);
char addKeyL(char, char);
char addKeyU(char, char);

// Store keyword in a string
    string keyword;
// 'upper[]' and 'lower[]' contain the English alphabets 
    char upper[27];
    char lower[27];
  
int main(int argc, char* argv[])
{
    // Allow execution of program only if the command-line arguments
    // are proper
    if (argc == 2)
    {
        // Copy keyword to string 'keyword' from command-line
        keyword = argv[1];
    }
    else
    {
        // Notify of correct usage
        printf("Usage: ./vigenere <keyword>\n");
        return 1;
    }
    
    // Check if all the characters of the keyword are alphabets
    for (int i = 0; i < strlen(keyword); i++)
    {
        if (isalpha(keyword[i]))
            continue;
        // Exist program returning 1, if keyword characters are not alphabets
        else
        {
            printf("Keyword should only consist of 'ALPHABETS'\n");
            return 1;
        }
    }

    // Store 'upper[]' with Upper alphabets
    for (int i = 0, n = 65; i < 26; i++, n++)
        upper[i] = n;
    upper[26] = '\0';
    
    // Store 'lower[]' with lower alphabets
    for (int i = 0, n = 97; i < 26; i++, n++)
        lower[i] = n;
    lower[26] = '\0';
    
    // Store Plain Text in string 'plainText'
    string plainText;
    plainText = GetString();
    
    // Store Cipher Text in string 'cipherText'
    char cipherText[100];
    char ki;
    int l;
    
    // Go through all characters of 'plainText' to obtain
    // corresponding 'cipherText'
    for (int i = 0, z = 0; i < strlen(plainText); i++)
    {
        // Enter when Plain Text is an alphabet
        if (isalpha(plainText[i]))
        {
            // use 'z' to move through the Keyword
            // use 'i' to move through the Plain Text
            ki = getkey(z);
            // Pass one character and its corresponding keyletter as
            // arguments to the 'convert()' function to obtain Cipher Text
            cipherText[i] = convert(plainText[i], ki);
            z++;
        }
        // Enter when Plain Text is not an alphabet
        else
        {
            cipherText[i] = plainText[i];
        }
            l = i;
    }
    cipherText[l + 1] = '\0';
    
    // Output Cipher Text
    for (int i = 0; cipherText[i] != '\0'; i++)
        printf("%c", cipherText[i]);
        
    printf("\n");
    return 0;
}

/*
 * Function that returns appropriate keyletter, choosing it from 
 * the keyword that was input
 */
char getkey(int i)
{
    char k;
    // Do not overshoot the keyword
    if (i >= strlen(keyword))
        i = i % strlen(keyword);
     k = keyword[i];
 
     return k;
}

/*
 * Function to convert Plain Text into Cipher Text
 */
char convert(char p, char k)
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
           c = addKeyU(p, k);
           return c;
        }
        // If the character is not an Upper alphabet then it 
        // should be a lower alphabet
        else
        {
            // Call a function to add 'key' to the 'alphabet'
            c = addKeyL(p, k);
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
char addKeyU(char p, char k)
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

    // Store equivalent number for the Keyletter in 'k1'
    int k1;
    // Used since the keyword can contain both upper
    // and lower alphabets
    if (isupper(k))
        k1 = k - 65;
    else
        k1 = k - 97;
     
    // Cipher text remains unchanged for A or a in the keyword 
    if (k1 == 0)
        c = upper[j];

    // Required for the proper working of the following loop    
    j++;
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
char addKeyL(char p, char k)
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
    
    // Store in 'k1' the equivalent number for the keyletter
    int k1;
    if (isupper(k))
        k1 = k - 65;
    else
        k1 = k - 97;

    if (k1 == 0)
        c = lower[j];

    j++;


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
