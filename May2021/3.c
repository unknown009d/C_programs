#include "drb.h"

/* Dynamic Allocation of Memory */

void DMSA()
{
    /* _Division Multiplication Subtration Addition_ */
    int *a, *b;

    a = (int *)malloc(sizeof(int));
    b = (int *)malloc(sizeof(int));

    *a = input("Enter the 1st Number : ");
    *b = input("Enter the 2nd Number : ");

    printf("\nThe Division is : %f", (float)*a / (float)*b);
    printf("\nThe Multiplication is : %d", *a * *b);
    printf("\nThe Subtraction is : %d", *a - *b);
    printf("\nThe Addition is : %d", *a + *b);

    free(a);
    free(b);
}

void primeNumber()
{
    /* Prime Number Calculation */
    int *num, *count, *primeCounter;

    num = (int *)malloc(sizeof(int));
    count = (int *)malloc(sizeof(int));
    primeCounter = (int *)malloc(sizeof(int));

    *primeCounter = 0;

    *num = input("Enter the number : ");

    if (*num == 0)
    {
        printf("0 is neither prime nor composite");
        return;
    }

    for (*count = 1; *count < *num; (*count)++)
    {
        if (*num % *count == 0)
            (*primeCounter)++;
    }
    printf("%d\n%d is ", *primeCounter, *num);
    if (*primeCounter == 1)
    {
        printf("prime Number.");
    }
    else
    {
        printf("not prime number.");
    }
    free(num);
    free(count);
    free(primeCounter);
}
