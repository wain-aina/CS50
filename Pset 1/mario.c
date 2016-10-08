/**
 * mario.c
 *
 * Olivia Brown
 * olivia.brown@aupschool.org
 *
 * Prints a half pyramid of an inputted height
 *
 */
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Pyramid height variable
    int heightInput = 0;
    
    // Collects input for height until valid 
    do
    {
        printf("Height: ");
        heightInput = GetInt();
    } 
    while (heightInput > 23 || heightInput < 0);

    // Prints the correct number of rows
    for(int i = 0; i < heightInput; i++) 
    {
        // Prints the correct number of spaces
        for(int space = 0; space < heightInput - i - 1; space++)
        {
            printf("%s", " ");
        }
        
        // Prints the correct number of hashtags
        for(int hash = 0; hash < i + 2; hash++)
        {
            printf("#");
        }
        printf("\n");
	}	
}