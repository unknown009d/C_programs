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

void perfectNumMain()
{
    int perfectNum = recPerfectNumber(input("Enter any number : "), 1, 0);
    if (perfectNum != 0)
        printf("-> Perfect Number");
    else
        printf("-> Not a perfect number");
}

/* Palindrome Check */

int palindromeCheck(int data, int count, int result)
{
}

/* Addition and Subtraction in same Reccursive Function */

void add_subOLD(int num, int result)
{
    if (num != 0)
    {
        result += num;
        debug(num);
        add_subOLD(--num, result);
    }
    else
    {
        printf("Sum = %d\n", result);
    }
    printf("\n--BEF--\nresult : %d, num : %d\n--AFT--\n", result, num);
    if (num == 0)
    {
        result = 0;
    }
    printf("result : %d, num : %d\n", result, ++num);
    // if (num > 0)
    // {
    //     result -= num;
    // }
}

void add_sub_NT(int num, int resultSUB, int resultADD)
{
    if (num == 1)
    {
        resultADD += num;
        printf("Addition : %d\n", resultADD);
        printf("Subtraction : %d\n", resultSUB);
        return;
    }
    else
    {
        resultSUB -= num;
        resultADD += num;
    }
    add_sub_NT(--num, resultSUB, resultADD);
}

int add_sub(int num, int stNum, int result)
{
    if (stNum == 0)
        stNum = num - 1;
    if (num == 1)
    {
        printf("Addition : %d\n", result + num);
        return num;
    }
    else
    {
        result += num;
    }
    result = add_sub(--num, stNum, result) - (num + 1);
    if (num == stNum)
        printf("\nSubtraction : %d", result);
    return result;
}

int add_subMAIN(int num, int result)
{
    if (num == 1)
    {
        printf("Addition : %d\n", result + num);
        return num;
    }
    else
        result += num;
    result = add_subMAIN(--num, result) - (num + 1);
    return result;
}

int tailCall(int num, int result)
{
    if (num != 1)
    {
        tailCall(--num, result += num);
    }
    else
    {
        printf("Addition is : %d\n", result + num);
        return result = num;
    }
    debug(num);
    return result -= num + 1;
}

void sample(int num, int result)
{
    for (; num != 0; num--)
    {
        result += num;
    }
    debug(result);
    calcTimeTaken();

} // 0.0018 - 0.0020

void sampleREC(int num, int result)
{
    if (num != 0)
        sampleREC(--num, result += num);
    else
    {
        debug(result);
        calcTimeTaken();
    }
}

void d_program()
{
    sampleREC(5, 0);
}