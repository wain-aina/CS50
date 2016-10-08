/**
 * hello.c
 *
 * Olivia Brown
 * olivia.brown@aupschool.org
 *
 * Print hello to user name from command line input
 */
#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    // Ends program and tells user how to use command line if input is incorrect
    if (argc != 2)
    {
        printf("Usage: ./hello <name>\n");
        return 1;
    }
    // Assigns variable to second element of argv
    string name = argv[1];
    
    // Prints hello and name
    printf("hello, %s\n", name);
}