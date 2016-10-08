/**
 * fahrenheit.c
 *
 * Olivia Brown
 * olivia.brown@aupschool.org
 *
 * Converts Celcius to Fahrenheit given an input
 */

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("C: ");
    float degreeInput = GetFloat();
    float degreeOutput = (((degreeInput * 9) / 5) + 32);
    printf("F: %.1f\n", degreeOutput);
}

