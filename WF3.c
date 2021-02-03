#include "drb.h"

void yShape()
{
    int count, inCount, range = 3;

    for (count = 0; count <= range - 1; count++)
    {
        for (inCount = 1; inCount <= count; inCount++)
            printf(" ");
        printf("%c", 65 + count);
        for (inCount = count; inCount <= range - 1; inCount++)
            printf(" ");
        for (inCount = range - 2; inCount >= count; inCount--)
            printf(" ");
        printf("%c", 65 + count);
        printf("\n");
    }
    for (inCount = 0; inCount <= range - 1; inCount++)
        printf(" ");
    printf("%c\n", 65 + count);
    for (count = 0; count <= range - 1; count++)
    {
        for (inCount = 0; inCount <= range - 1; inCount++)
            printf(" ");
        printf("%c", 49 + count);
        printf("\n");
    }
}

void ptrnPractice()
{
    int ct, inCt, range = 4;

    for (ct = 0; ct <= range; ct++)
    {
        for (inCt = ct; inCt >= 0; inCt--)
            printf("%d ", inCt);
        for (inCt = 0; inCt < range - ct; inCt++)
            printf("%d ", inCt + 1);
        printf("\n");
    }
}

void WF3_Q1()
{
    int range, _stRange, result = 0, _stResult, count;
    printf("Enter the Range : ");
    scanf("%d", &range);
    _stRange = range;
    printf("\n");
    for (; _stRange >= 1; _stRange--)
    {
        printf("%d^%d ", _stRange, _stRange);
        if (_stRange > 1)
            printf("+ ");

        _stResult = 1;
        for (count = 1; count <= _stRange; count++)
            _stResult *= _stRange;
        result += _stResult;
    }
    printf(" = %d", result);
    printf("\n");
}

void WF3_Q1_2()
{
    int range, _stRange, result = 0, _stResult, count;
    printf("Enter the Range : ");
    scanf("%d", &range);
    _stRange = range;
    printf("\n  ");
    for (; _stRange >= 1; _stRange--)
    {
        _stResult = 1;
        for (count = 1; count <= _stRange; count++)
            _stResult *= _stRange;

        result += _stResult;
    }
    _stRange = range;
    for (; _stRange >= 1; _stRange--)
    {
        printf("%d^%d ", _stRange, _stRange);
        if (_stRange > 1)
            printf("+ ");
    }
    _stRange = range;
    printf("\n= ");
    for (; _stRange >= 1; _stRange--)
    {
        _stResult = 1;
        for (count = 1; count <= _stRange; count++)
            _stResult *= _stRange;
        printf("%d ", _stResult);
        if (_stRange > 1)
            printf("+ ");
    }

    printf("\n= %d", result);
    printf("\n");
}

void d_program()
{
}