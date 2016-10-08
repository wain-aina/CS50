/**
 * hello.c
 *
 * Olivia Brown
 * olivia.brown@aupschool.org
 *
 * prints string "hello, world"
 */
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("Enter your name: ");
    string name = GetString();
    printf("hello, %s\n", name);
}