/**
 * caesar.c
 *
 * Olivia Brown
 * olivia.Brown@aupschool.org
 *
 * Encrypts a message using a Caesar cipher
 */
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Gets key for cipher
    string key = argv[1];
    
    // Ends program with exit code of 1 if incorrect input
    if (argc != 2)
    {
        printf("Usage: ./caesar <key>\n");
        return 1;
    }
    
    // Continues if number of inputs is correct
    else
    {
        // Converts key from string to an integer
        int k = atoi(key) % 26;
        
        // Ends program if key is invalid (0)
        if (k == 0)
        {
            printf("Key must not be equal to zero. Try again\n");
            return 1;
        }
    
        // Input for message to encrypt
        string text = GetString();
        if (text != NULL)
        {
            // Method to encrypt
            for (int i = 0, n = strlen(text); i < n; i++)
            {
                int character = 0;    
        
                // Checks if text is upper or lower case
                // Encrypts uppercase
                if (isupper(text[i]))
                {
                    character = (((int) text[i] - 65 + k) % 26) + 65;
                    printf("%c", (char) character);
                }
                // Encrypts lowercase
                else if (islower(text[i]))
                {
                    character = (((int) text[i] - 97 + k) % 26) + 97;
                    printf("%c", (char) character);
                }
                else
                {
                    printf("%c", text[i]);
                }
            }
            printf("\n");
            return 0;
        }
    }
}