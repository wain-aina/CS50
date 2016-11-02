/**
 * caesar.c
 *
 * Olivia Brown
 * olivia.Brown@aupschool.org
 *
 * Encrypts a message using a Vigenere cipher
 **/
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Variables
    int shift, keyValue;
 
    // Ends program if incorrect input
    if (argc != 2)
    {
        printf("Usage: vigenere <key>\n");
        return 1;
    }
 
    // Key is second input
    string key = argv[1]; 
 
    // Loop through all the keys and end if a key is not a letter
    for(int i = 0, j = strlen(key); i < j; i++)
    {
        if (!isalpha(key[i]))
        {   
            printf("Key must be letters.\n");
            return 1;
        }
    }
 
    // Get text to encrypt
    string text = GetString();   
 
    // Encrypt each character and print
    for(int i = 0, j = 0, length = strlen(text); i < length; i++, j++)
    {
        // Starts key from beginning if shorter than text
        if (j >= strlen(key))
        {
            j = 0;
        }
 
        // Set keyValue to key[j]
        keyValue = key[j]; 
 
        // Skip key[j] if text[i] is not a letter
        if (!isalpha(text[i]))
        {
            j = (j - 1);
        }  
 
        // Makes A = 0 and Z = 25 for uppercase
        if ((keyValue >= 'A') && (keyValue <= 'Z'))
        {
            keyValue = (keyValue - 'A');
        }
 
        // Makes a = 0 and z = 25 for lowercase
        if ((keyValue >= 'a') && (keyValue <= 'z'))
        {
            keyValue = (keyValue - 'a');
        }
 
        // Encrypt
        shift = (text[i] + keyValue);
 
        // Wrapping after Z for uppercase
        if (isupper(text[i]) && (shift > 'Z'))
        {
            shift = (shift - 26);
        }
 
        // Wrapping after z for lowercase
        if (islower(text[i]) && (shift > 'z'))
        {
            shift = (shift - 26);
        }
 
        // Print encrypted result for letters
        if (isalpha(text[i]))
        {
            printf("%c", shift);
        }
 
       // Print without encryption for non-alphabetical  
        else
        {
            printf("%c", text[i]);
        }
    }  
    printf("\n");
    return 0;
}