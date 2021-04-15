#include "drb.h"

void listArray(int arrayVar[], int memCount)
{
    if (memCount == 0)
    {
        printf("[null]");
        return;
    }
    int i = 0;
    putchar('[');
    do
    {
        printf("%d", arrayVar[i]);
        if (i < memCount - 1)
            printf(", ");
        i++;
    } while (i < memCount);
    putchar(']');
}

int numSegment(int num, int *retArray, int count)
{
    if (num == 0)
        return count;
    retArray[count] = num % 10;
    return numSegment(num /= 10, retArray, ++count);
}

int numSegmentMain()
{
    int data = input("Enter any Data : ");
    int segmentedArray[10];
    int numLen = numSegment(data, segmentedArray, 0);
    listArray(segmentedArray, numLen);
}

/* ArmStrong */

int intLen(int data)
{
    if (data == 0)
        return 0;
    return 1 + intLen(data /= 10);
}

int powerCalc(int num, int pow)
{
    if (pow == 1)
        return num;
    return num * powerCalc(num, --pow);
}

int armStrongNumber(int data, int count)
{
    static int _tempData = 0, retVal = 0;
    if (count == 0)
    {
        _tempData = data;
        retVal = 0;
    }
    if (data == 0)
        return retVal == _tempData ? 1 : 0;
    retVal += powerCalc(data % 10, intLen(_tempData));
    return armStrongNumber(data /= 10, ++count);
}

void armStrongRange(int initial, int hiRange)
{
    if (initial > hiRange)
        return;
    int chkArmStrong = armStrongNumber(initial, 0);
    chkArmStrong ? debug(initial) : putchar(0);
    armStrongRange(++initial, hiRange);
}

void d_program()
{
    int inpRange = input("Enter the range starting from 10 to ");
    armStrongRange(10, inpRange);
}