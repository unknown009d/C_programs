#include "drb.h"

/* ====================================Q1============================================== */
/* Find the largest number against the given user input (FOR LOOP) */
void largestNumFOR()
{
    int count = 0,
        _inputCheck = 1,
        _tempData,
        largestNum = 0;

    printf("Enter any character(x) value to stop and find the largest number..\n\n");
    for (;;)
    {
        if (_inputCheck == 1)
        {
            count++;
            printf("Enter the value of %d : ", count);
            _inputCheck = scanf("%d", &_tempData);
            if (_tempData > largestNum)
                largestNum = _tempData;
        }
        else
        {
            break;
        }
    }
    (count > 1) ? printf("\nThe Largest Number is : %d", largestNum) : printf("\nProgram End !");
}

/* Find the largest number against the given user input (WHILE LOOP) */
void largestNumWHILE()
{
    int count = 0,
        _inpChk = 1,
        _tempInp,
        largestNum = 0;

    printf("Enter any any character(x) to find the largest among given numbers \n\n");

    while (1)
    {
        if (_inpChk == 1)
        {
            printf("Enter the value of %d : ", ++count);
            _inpChk = scanf("%d", &_tempInp);
            if (_tempInp > largestNum)
                largestNum = _tempInp;
        }
        else
        {
            break;
        }
    }
    count > 1 ? printf("\nThe Largest number is : %d", largestNum) : printf("\nProgram End !");
}

/* Find the largest number against the given user input (DO WHILE LOOP) */
void largestNumDOWL()
{
    int count = 0,
        _inpChk = 1,
        _tmpInp,
        largestNum = 0;

    printf("..Enter any character to find the largest number.. \n\n");

    do
    {
        if (_inpChk == 1)
        {
            printf("Enter the value of %d : ", ++count);
            _inpChk = scanf("%d", &_tmpInp);
            if (_tmpInp > largestNum)
                largestNum = _tmpInp;
        }
        else
        {
            break;
        }
    } while (1);

    if (count > 1)
    {
        printf("\n%d is the largest number", largestNum);
    }
}

/* Find the largest number against the given user input (GOTO LOOP) */
void largestNumGOTO()
{
    int count = 0,
        _inpChk,
        _tmpInp,
        largestNum = 0;

    printf("..Enter any character value(x) to stop..\n\n");

IR:
    printf("Enter the value of %d : ", ++count);
    _inpChk = scanf("%d", &_tmpInp);
    if (_tmpInp > largestNum)
        largestNum = _tmpInp;

    if (_inpChk == 1)
        goto IR;
    if (count > 1)
        printf("\nLargest Number : %d", largestNum);
}

/* Find the largest number against the given user input (Recussion LOOP) */
void largestNumREC()
{
    static int _inpChk = 1, largeNum = 0;
    if (_inpChk == 1)
    {
        int _tmpNum = 0;
        printf("Enter the Value : ");
        _inpChk = scanf("%d", &_tmpNum);
        if (_tmpNum > largeNum)
            largeNum = _tmpNum;
        largestNumREC();
    }
    else
        printf("\n%d - Largest Number", largeNum);
}

/* ======================================================================= */

/* ===================================Q2================================== */
/* X^1 - X^2 + X^3 + ... X^n (with FOR) */
int calcPow(int value, int pow, int result)
{
    if (pow >= 1)
    {
        result *= value;
        calcPow(value, --pow, result);
    }
    else
    {
        return result;
    }
}
void Q2()
{
    int x = 0, n = 0, result = 0, supRes = 0;
    printf("Enter any number : ");
    scanf("%d", &x);
    printf("Enter the number of terms for power : ");
    scanf("%d", &n);
    for (int count = 1; count <= n; count++)
    {
        switch (count % 2)
        {
        case 0:
            result -= calcPow(x, count, 1);
            break;
        case 1:
            result += calcPow(x, count, 1);
            break;
        default:
            break;
        }
    }
    printf("\nResult : %d", result);
}

/* Sample Try Program */
int recPow(int value, int pow)
{
    static int result = 1;
    if (pow != 0)
    {
        result *= value;
        recPow(value, --pow);
    }
    else
    {
        return result;
    }
}

void recPowMain()
{
    int num, numPow;
    printf("Enter (x) to stop :\n\n");
PG1:
    printf("\nEnter the Calculation (with a space): ");
    int chkInp = scanf("%d %d", &num, &numPow);
    printf("\n%d ^ %d = %d\n\n", num, numPow, recPow(num, numPow));
    if (chkInp != 0)
    {
        goto PG1;
    }
    
    printf("Program End");
}

void d_program()
{

}