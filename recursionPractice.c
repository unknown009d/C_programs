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

void d_program()
{
    ptrnVertical(5, '1', 1);
}