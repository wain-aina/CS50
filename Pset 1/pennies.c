/**
 * pennies.c
 *
 * Olivia Brown
 * olivia.brown@aupschool.org
 *
 * Returns total number of pennies if the pennies doubles every day of a month
 *
 */
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long long pennies = 0;
    int days = 0;
    
    // Asks for an input of days in month
    do
    {
        printf("Days in month: \n");
        days = GetInt();
    }
    // Asks for an input until the number of days in month is valid
    while (days > 31 || days < 28);
    
    // Asks for an input of pennies for the first day
    do
    {
        printf("Pennies on first day: \n");
        pennies = GetInt();
    }
    // Asks for an input until the pennies value is valid
    while (pennies <= 0);
    
    long long total = 0;
    
    // For each day, double the pennies and add to total
    for (int i=1; i <= days; i++)
    {
        total += pennies;
        pennies *= 2;
    }
    
    // Convert pennies to dollars and print result
    double totalDollars = ((double) total) / 100;
    printf("$%.2f\n", totalDollars);
}