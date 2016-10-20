/**
 * calc.c
 *
 * Olivia Brown
 * olivia.Brown@aupschool.org
 *
 * A simple calculator using command line input
 */

#include <stdio.h>
#include <cs50.h>

int main(int argc, char *argv[])
{
    
    // Define variables
    float firstNum, secondNum, ans;
    int temp;
    char operation;
    
    // End program and tells user how to use command line if input is incorrect
    if ( argc != 4)
    {
        printf("Usage: calc [operand_1] [operator] [operand_2]\n");
        return 1;
    } 

    // Converts input to float
    firstNum = atof(argv[1]);
    secondNum = atof(argv[3]);
    
    // Converts input to char *
    operation = *argv[2];

    // Switches operation depending on input
    switch (operation)
    {
        // Case addition
        case '+':
            ans = firstNum + secondNum;
            printf("%f\n", ans);
            break;
        // Case subtraction
        case '-':
            ans = firstNum - secondNum;
            printf("%f\n", ans);
            break;  
        // Case multiplication
        case 'x':
            ans = firstNum * secondNum;
            printf("%f\n", ans);
            break;    
        // Case division
        case '/':
            ans = firstNum / secondNum;
            printf("%f\n",ans);
            break;
        // Case modulo
        case '%':
            temp = (int) (firstNum / secondNum);
            ans = firstNum - (secondNum * temp);
            printf("%f\n",ans);
            break;
        // Ends program if the operator is not +, -, x, /, or %
        default:
            printf("Invalid Operator \n");
            return 1;
        }
    return 0; 
}
