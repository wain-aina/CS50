/**
 * pennies.c
 *
 * Olivia Brown
 * olivia.brown@aupschool.org
 *
 * Returns total number of pennies if the pennies doubles every day of a month
 */
 
#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    // Ends program and tells user how to use command line if input is incorrect
    if (argc != 3) 
    {
        printf("Usage: ./pennies <days> <pennies on first day>\n");
        return 1;
    }

    // Assigns number of days to second element in input
    int days = atoi(argv[1]);
    // Assigns number of pennies to third element in input
    int pennies = atoi(argv[2]);

    if (days < 28 || days > 31 || pennies < 0) 
    {
        printf("Days must be between 28 and 31. Pennies cannot be negative.\n");
        return 1;
    }
    
    // Defines long long because it could easily get out of range
    long long total = pennies;
    
    // Add double the amount of pennies of the previous day for every day
    for(int i = 1; i < days; i++)
    {
        total += pennies * pow(2,i);
    }
        
    // Print the total as dollars and cents
    printf("$%.2f\n", ((double) total) / 100);
}