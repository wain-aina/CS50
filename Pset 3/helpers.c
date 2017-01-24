/**
 * helpers.c
 *
 * CS50 AP
 * Sort Race
 * 
 * Name: Olivia Brown
 *
 * Helper functions for the sort race
 */

#include <cs50.h>
#include "helpers.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Returns true if str is a valid flag (-a, -b, -r, or -s), false otherwise
 */
bool check_flag(char* str)
{ 
    if (strcmp(str, "-a") != 0 && strcmp(str, "-b") != 0 && 
    strcmp(str, "-r") != 0 && strcmp(str, "-s") != 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

/**
 * Sorts array of n values using bubble sort.
 */
void bubble(int values[], int n)
{ 
    int i, j, temp;
    
    for (i = 0 ; i < ( n - 1 ); i++)
    {
        for (j = 0 ; j < n - i - 1; j++)
        {
            if (values[j] > values[j + 1])
            {
                temp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = temp;
            }
        }
    }
    return;
}

/**
 * Sorts array of n values using selection sort.
 */
void selection(int values[], int n)
{ 
    int i, j, min, temp;

    for (i = 0 ; i < ( n - 1 ); i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (values[min] > values[j])
            {
                min = j;
            }
        }
        if (min != i)
        {
            temp = values[i];
            values[i] = values[min];
            values[min] = temp;
        }
    }
    return;
}

/**
 * Sorts array of n values using insertion sort.
 */
void insertion(int values[], int n)
{ 

    int i, j, element;
   
    for (i = 1 ; i <= n - 1; i++)
    {
        element = values[i];
        j = i;
 
        while ( j > 0 && element < values[j - 1])
        {
            values[j] = values[j - 1];
            j--;
            values[j] = element;
        }
    }
    return;
}

