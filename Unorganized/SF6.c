/* Saturday Feb. 6th 2021, Programs */
#include "drb.h"

int EvenOrOdd(int num, char type)
{
    if (type == 'E' || type == 'e')
    {
        printf("Check Even");    
    }
    else if(type == 'O' || type == 'o')
    {
        printf("Check Odd");
    }
}

void d_program()
{
    char type;
    int num, result;
    printf("Enter your choice (O-Odd / E-Even) : ");
    scanf("%c", &type);
    printf("Enter the Number : ");
    scanf("%d", &num);
    result = EvenOrOdd(num, type);
}