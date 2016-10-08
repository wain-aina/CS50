/**
 * credit.c
 *
 * Olivia Brown
 * olivia.brown@aupschool.org
 *
 * Determines if an inputted credit card number is valid
 */
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNUMBER 16 

int main(void)
{
    // Ask for an inputted credit card number until nonnegative
    printf("Number: ");
    long long creditNumber = GetLongLong();
    
    // Save creditNumber as string
    char stringNumber[MAXNUMBER];
    sprintf(stringNumber, "%lld", creditNumber);
    
    // Save length of creditNumber as int
    int len = strlen(stringNumber);
    
    // If not a valid length, INVALID
    if (len < 13 || len == 14 || len > 16 )
    {
        printf("INVALID\n");
        return 0;
    }
    
    // Enter number into an array
    int number[len];
    for (int i = 0; i < len; i++)
    {
        number[i] = stringNumber[i] - '0';
    }
    
    // Multiply every other digit by 2 & add digits together
    int sum = 0, j = 1;
    for (int i = len - 1; i >= 0; i--)
    {
        if (j % 2 == 0)
        {
            sum += number[i] * 2 % 10;
            if (number[i] * 2 >= 10)
            {
                sum += 1; 
            }
        } 
        // Add not multiplied numbers to sum
        else
            sum += number[i];
        j++; 
    }

    // Check for and print card type  
    if (number[0] == 3 && (number[1] == 4 || number[1] == 7) && sum % 10 == 0)
    {
        printf("AMEX\n");
    }
    else if (number[0] == 5 && number[1] > 0 && number[1] < 6 && sum % 10 == 0)
    {
        printf("MASTERCARD\n");
    }
    else if (number[0] == 4 && sum % 10 == 0)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}   