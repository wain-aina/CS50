/**
 * rng.c
 *
 * Olivia Brown
 * olivia.Brown@aupschool.org
 *
 * Generates n pseudo-random numbers within max
 **/

// Include and define
#define _XOPEN_SOURCE
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LIMIT 65536

int main(int argc, string argv[])
{
    // Ends program if incorrect number of inputs
    if (argc != 3 && argc != 4)
    {
        printf("Usage: ./rng n max [s]\n");
        return 1;
    }
    
    // Capture first and second argument as ints
    int n = atoi(argv[1]);
    int max = atoi(argv[2]);
    
    // Ends program if max greater than limit or less than 0
    if (max > LIMIT || max < 0)
    {
        printf("max must be greater than 0 and less than 65536\n");
        return 1;
    }
    // If seed is provided, initialize with seed
    if (argc == 4)
    {
        srand48((long int) atoi(argv[3]));
    }
    // If seed is not provided, initialize with time
    else
    {
        srand48((long int) time(NULL));
    }
    
    // Generate and print n random numbers
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * max));
    }
    return 0;
}
