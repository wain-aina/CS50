/**
 * isbn.c
 *
 * Olivia Brown
 * olivia.brown@aupschool.org
 *
 * Determines if an ISBN number is valid
 *
 */
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Asks user for an ISBN input value
    printf("ISBN Number: \n");
    long long isbn = GetLongLong();
    int isbnValue = 0, i = 0;
    
    // For the 10 digits in the ISBN number
    for(i = 10 ; i > 0 ; i--)
    {
        // Multiplies the rightmost digit by its place number and adds to total
        isbnValue += (isbn % 10) * i;
        // Shifts every place one to the right
        isbn = isbn / 10;
    }
    
    // If evenly divisible by 11, valid
    if (isbnValue % 11 == 0 )
    {
        printf("YES\n");
    }
    // If not evenly divisible by 11, invalid
    else 
        printf("NO\n");
}