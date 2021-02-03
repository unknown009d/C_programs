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

void WF3_Q2()
{
    int range, count, result = 0, stResult = 1;
    printf("Enter the Range : ");
    scanf("%d", &range);
    printf("\n");
    for (count = 1; count <= range; count++)
    {
        printf("%d ", stResult);
        result += stResult;
        if (count != range)
            printf("+ ");
        stResult = (stResult * 10) + (count + 1);
    }
    printf(" = %d", result);
}

void WF3_Q3()
{
    int range, num, count, result = 0, stResult;

    printf("Enter any Number : ");
    scanf("%d", &num);
    stResult = num;

    printf("Enter the Range : ");
    scanf("%d", &range);

    for (count = 1; count <= range; count++)
    {
        printf("%d ", stResult);
        result += stResult;
        if (count != range)
            printf("+ ");
        stResult = (stResult * 10) + (num);
    }
    printf(" = %d", result);
}

void WF3_Q4()
{
    int range, count, inCount, result = 0;
    printf("Enter the Range : ");
    scanf("%d", &range);
    printf("\n");
    for (count = 1; count <= range; count++)
    {
        printf("(");
        for (inCount = 1; inCount <= count; inCount++)
        {
            printf("%d", inCount);
            if (inCount != count)
                printf("+");
            result += inCount;
        }
        printf(")");

        if (count != range)
            printf("+");
    }
    printf(" = %d", result);
}

void d_program()
{
    int num, range, count, inCount, result = 0, stResult = 0, pwResult = 1, asstResult;

    printf("Enter a Number : ");
    scanf("%d", &num);
    printf("Enter the Range : ");
    scanf("%d", &range);
    printf("\n\n");
    for (count = 0; count <= range; count++)
    {
        printf("{%d+%d^(%d+%d)}",
               count, num, count + 1, num);
        if (count != range)
            printf("+");
    }
    printf("\n\n= ");
    for (count = 0; count <= range; count++)
    {
        printf("(%d^%d)", count + num, (count + 1) + num);
        if (count != range)
            printf("+");
    }
    printf("\n\n= ");
    for (count = 0; count <= range; count++)
    {
        asstResult = 1;
        stResult = count + num;
        pwResult = (count + 1) + num;
        for (inCount = 1; inCount <= pwResult; inCount++)
        {
            asstResult *= stResult;
        }
        printf("(%d)", asstResult);
        result += asstResult;
        if(count != range)
            printf("+");
    }
    printf("\n\n= %d", result);
}