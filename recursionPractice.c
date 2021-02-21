#include "drb.h"

int recAdd(int num, int count, int sum)
{
    if (count != 0)
        sum = recAdd(num, --count, sum = sum + num);
    return sum;
}

void recAdd_main()
{
    int fNum = input("Enter the number : ");
    int count = input("Enter the number of times to add : ");
    printf("Addition of %d added %d times is %d", fNum, count, recAdd(fNum, count, 0));
}

int calcLen(int data, int count)
{
    if (data != 0)
        count = calcLen(data /= 10, ++count);
    return count;
}

int calcPow(int data, int length, int retOP)
{
    if (length != 0)
        retOP = calcPow(data, --length, retOP *= data);
    return retOP;
}

int recSegmentation(int data, int retOP, int length)
{
    if (data != 0)
    {
        int inData = data % 10;
        retOP += calcPow(inData, length, 1);
        retOP = recSegmentation(data /= 10, retOP, length);
    }
    return retOP;
}

void armstrongMain()
{
    int data;
    data = input("Enter the Number to check armstrong : ");
    int inpLen = calcLen(data, 0);
    int armStrong = recSegmentation(data, 0, inpLen);
    armStrong == data ? printf("%d is armstrong..", data) : printf("%d is not an armstrong", data);
}

void ptrnHorizontal(int count, char sign)
{
    if (count != 0)
    {
        printf("%c ", sign);
        ptrnHorizontal(--count, ++sign);
    }
}

void ptrnVertical(int count, char sign, int inCount)
{
    if (count != 0)
    {
        ptrnHorizontal(inCount, sign);
        printf("\n");
        ptrnVertical(--count, sign, ++inCount);
    }
}

void ptrnMain()
{
    ptrnVertical(5, '1', 1);
}

void add(int x, int maxLength)
{
    static int result;
    if (maxLength >= 0)
    {
        if (maxLength == 0)
        {
            printf("Result : %d\n", result);
            result = 0;
        }
        else
            result += x;
        add(x, --maxLength);
    }
}

void test()
{
    add(2, 5);
    printf("------------\n");
    add(3, 4);
    printf("------------\n");
    add(2, 8);
    printf("------------\n");
    add(3, 2);
}

int primeCounter = 0, reccursionCounter = 0, primeStNum = 0;

int primeChecker(int num)
{
    if (reccursionCounter == 0)
        primeStNum = num;

    if (num != 0)
    {
        if (primeStNum % num == 0)
            primeCounter++;
        reccursionCounter++;
        primeChecker(--num);
        if (primeCounter <= 2)
            num = 1;
        else
            num = 0;
    }

    return num;
}

void d_program()
{
    printf("%d", primeChecker(7));
}