/**
 * crack.c
 *
 * Olivia Brown
 * olivia.Brown@aupschool.org
 *
 * Decrypts a password
 **/

#define _XOPEN_SOURCE
#include <stdio.h>
#include <string.h>
#include <unistd.h>

// Dictionary file
#define DICT "/usr/share/dict/words"

int tryWord(char *pass, char *givenText);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: crack <password to crack>\n");
        return 1;
}
    // Initialize numPass, number of passwords tried
    int numPass = 0;
    
    // Value of tryWord()
    int result;
    
    // Holds dictionary word
    char buf[30];
    FILE *file;

    // Open dictionary
    file = fopen(DICT, "r");
    
    // If file fails
    if (!file)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Extract word from each line of dictionary
    while (fgets(buf, 30, file) != NULL)
    {
        int i = 0;
        while (buf[i] != '\n' && buf[i] != '\r')
        {
            i++;
        }
        buf[i] = '\0';

        // Check if word is a match
        result = tryWord(argv[1], buf);
        if (result)
        {
            printf("Password: %s\n", buf);
            return 0;
        }
        // Increase number of passwords tried
        numPass++;
        // Print number of passwords tried every 500
        if (numPass % 500 == 0)
        {
            printf("%d...\n", numPass);
        }
    }

    // If no passwords were successful, inform user
    printf("Could not find a match.\n");
    return 0;
}

// Test a dictionary word against a password & 4096 salts
int tryWord(char *pass, char *givenText)
{
    // Initialize
    int i = 0;
    int j = 0;
    
    // Result of crypt function
    char *cipher;
    
    // Possible characters
    char fullset[] = 
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789./";
    
    // 2-char buffer
    char salt[2];
     
    // Try 4096 different salt combinations
    for (i = 0; i < 64; i++)
    {
        for (j = 0; j < 64; j++)
        {

            salt[0] = fullset[i];
            salt[1] = fullset[j];

            // Run crypt with word and salt
            cipher = crypt(givenText, salt);  

            // Check for match
            if (strcmp(cipher, pass) == 0)
            {
                return i;
            }
        }
    }
    return 0;
}