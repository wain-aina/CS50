/**
 * initials.c
 *
 * Olivia Brown
 * olivia.brown@aupschool.org
 *
 * Prints initials given a name
 */

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Request name
    string name = GetString();
    
    // Print first character in uppercase
    printf("%c", toupper(name[0]));
   
    // Loop through the rest of characters in string
    for (int i = 0, n = strlen(name); i < n; i++)
    {
        // Assigns index i to space in between first and last name
        if ( name[i] == ' ') 
        {
            // Prints character immediatly following space
            printf("%c",toupper(name[i + 1])); 
        }
    }
    printf("\n"); 
}