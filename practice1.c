/* Thursday 18th Feb 2021 */
#include "drb.h"

/* --- Perfect Number (FOR) --- */
void perfectNumFOR()
{
    int number = input("Enter the Number : "),
        result = 0;
    for (int count = 1; count < number; count++)
    {
        if (number % count == 0)
            result += count;
    }
    if (result == number)
        printf("Perfect Number!");
    else
        printf("Not a perfect Number");
}

/* Perfect Number (DO WHILE) */
void perfectNumDOWHILE()
{
    int number = input("Enter the Number : "),
        result = 0,
        count = 1;

    do
    {
        if (number % count == 0)
            result += count;
        count++;
    } while (count < number);

    if (number == result)
        printf("Perfect Number ");
    else
        printf("Not a Perfect number");
}

/* Perfect Number (GOTO) */
void perfectNumGOTO()
{
    int number = input("Enter the Number : "),
        result = 0,
        count = 1;

PRS1:
    if (count < number)
    {
        if (number % count == 0)
            result += count;
        count++;
        goto PRS1;
    }
    else
    {
        if (result == number)
            printf("Perfect Number");
        else
            printf("Not an perfect number");
    }
}

/* Perfect Number (Recursion) */

int recPerfectNumber(int data, int count, int result)
{
    if (count < data)
    {
        if (data % count == 0)
            result += count;
        result = recPerfectNumber(data, ++count, result);
    }
    if (count == data)
    {
        if (result != data)
        {
            result = 0;
            count++;
        }
    }
    return result;
}

void d_program()
{
    int perfectNum = recPerfectNumber(input("Enter any number : "), 1, 0);
    if (perfectNum != 0)
        printf("-> Perfect Number");
    else
        printf("-> Not a perfect number");
}