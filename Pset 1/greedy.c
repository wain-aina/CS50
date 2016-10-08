/**
 * greedy.c
 *
 * Olivia Brown
 * olivia.brown@aupschool.org
 *
 * Determines the fewest number of coins to reach an inputted value
 */
 
#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int coins = 0;
    float inputChange;
    
    // Collects a float representing amount of change if value is valid
    do
    {
        printf("How much change do I owe you?\n");
        inputChange = GetFloat();
    }
    while (inputChange < 0);
    
    // Converts float to int representing total number of cents
    float cents = inputChange * 100.0;
    int centsLeft = round(cents);

    // If a quarter can be used, add a coin and remove 25 cents
    while(centsLeft >= 25) 
    {
        coins += 1;
        centsLeft -= 25;
    }
    
    // If a dime can be used, add a coin and remove 10 cents
    while(centsLeft >= 10) 
    {
        coins += 1;
        centsLeft -= 10;
    }
    
    // If a nickel can be used, add a coin and remove 5 cents
    while(centsLeft >= 5) 
    {
        coins += 1;
        centsLeft -= 5;
    }
    
    // If a penny can be used, add a coin and remove 1 cent
    while(centsLeft >= 1) 
    {
        coins += 1;
        centsLeft -= 1;
    }
    printf("%d\n", coins);
}