/*
 * greedy.c
 *
 * CS50; Problem Set 1
 * Jeevan B S
 *
 * Makes use of 'Greedy Algorithm' to hand out 'Small Change'
 */

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Use Boolean type number to Repeat Loop
    _Bool loopBreak = 1;
    float money;
    // Repeat till legitimate number is input
    while(loopBreak)
    {
        // Get desired input
        printf("Change Owed: ");
        money = GetFloat();
        // Check if input is negative
        if(money < 0)
            loopBreak = 1;
        else 
            loopBreak = 0;
    }
    
    // 'largeChange' contains non-decimal number
    int largeChange = 0;
    largeChange = money;
    // 'Change' contains decimal part (2 digits) converted to integer type
    int Change = 0;
    money = money * 100;
    Change = money;
    Change = Change % 100;
    // Convert all money to 'cents' and store in 'smallChange'
    int smallChange;
    largeChange = largeChange * 100;
    smallChange = largeChange + Change;
    
    // Make sure the third decimal number is not greater than 5
    // As in 4.2 being input and getting stored as 4.199
    money = money * 10;
    int checksum;
    checksum = money;
    if (checksum % 10 > 5)
       smallChange++;
       
    // 'num' is the number of coins to be dispensed with
    int num = 0;
    
    // Repeat loop till all the change has been handed out
  while (smallChange != 0)
  {
    // Use 'greedy algorithm' and dispense with the largest 
    // denomination possible
    
    // Hand out 25 cents
    if (smallChange >= 25)
    {
        // Increase 'num' every time change is handed out
        num++;
        smallChange = smallChange - 25;
    }
    // Hand out 10 cents
    else if (smallChange >= 10)
    {
        num++;
        smallChange = smallChange - 10;
    }
    // Hand out 5 cents
    else if (smallChange >= 5)
    {
        num++;
        smallChange = smallChange - 5;
    }
    // Hand out 1 cent
    else if (smallChange >= 1)
    {
        num++;
        smallChange = smallChange - 1;
    }
  }
    
    // Output the total number of coins to be given   
    printf("%d\n", num);    
    return 0;
}
