/**
 * skittles.c
 *
 * Olivia Brown
 * olivia.brown@aupschool.org
 *
 * Chooses a random number and asks a person to guess the number
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <cs50.h>

int main(void)
{
    // seed PRNG
    srand(time(NULL));

    // pick pseudorandom number in [0, 1023]
    int skittles = rand() % 1024;
    
    // TODO
    printf("I'm thinking of a number between 0 and 1023. What is it? ");
    
    // While loop runs until the guess is correct
    while(true)
    {
    
        // Collects a user's inputted guess
        int userInput = GetInt();
    
        // Gives hint if answer is too high or too low
        if (userInput > skittles) 
        {
            printf("Too many, guess again. ");
            }
            else if (userInput < skittles) 
        {
            printf("Too few, guess again. ");
        }
            // Tells the user they guessed correctly and ends the while loop
            else 
        {
            printf("Correct! Good job! ");
            break;
        }
    }
}