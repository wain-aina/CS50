/**
 * fahrenheit.c
 *
 * Olivia Brown
 * olivia.brown@aupschool.org
 *
 * Converts Celcius to Fahrenheit given a command line input
 */

#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    // Ends program and tells user how to use command line if input is incorrect
    if (argc != 2)
    {
        printf("Usage: ./hello <degrees>\n");
        return 1;
    }
    
    // Gets celcius from command line and converts to float
    float celsius = atof(argv[1]);
    
    // Convert to fahrenheit
    float fahrenheit = (celsius * 9) / 5 + 32;
    
    // Prints result of fahrenheit
    printf("F: %.1f\n", fahrenheit);
}