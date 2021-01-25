#include "drb.h"

void alphabeticLoop()
{
    int range = 8;
    printf("Enter the Range : ");
    scanf("%d", &range);
    printf("\n");
    for (int c = 0; c <= range; c++)
    {
        if (c == 0)
        {
            for (int d = 1; d <= range - c + 1; d++)
            {
                printf("%c ", d + 64);
            }
            for (int d = range - c; d >= 1; d--)
            {
                printf("%c ", d + 64);
            }
        }
        else
        {
            for (int d = 1; d <= range - c + 1; d++)
            {
                printf("%c ", d + 64);
            }
            for (int d = 2; d <= c + c; d++)
            {
                printf("  ");
            }
            for (int d = range - c + 1; d >= 1; d--)
            {
                printf("%c ", d + 64);
            }
        }
        printf("\n");
    }
}

void myRhombus()
{
    int range = 8;

    for (int counter = 1; counter <= range; counter += 2)
    {
        for (int ic = counter; ic <= range; ic++)
        {
            printf(" ");
        }
        for (int ic = 1; ic <= counter; ic++)
        {
            printf("* ");
        }
        printf("\n");
    }
    for (int counter = range - 2; counter >= 1; counter -= 2)
    {
        for (int ic = counter; ic <= range; ic++)
        {
            printf(" ");
        }
        for (int ic = 1; ic <= counter; ic++)
        {
            printf("* ");
        }
        printf("\n");
    }
}

void smRandomPattern()
{

    int dpHolding = 1;

    for (int counter = 1; counter <= 5; counter++)
    {
        int dpNum = dpHolding;
        for (int innerCounter = counter; innerCounter <= 5; innerCounter++)
        {
            if (innerCounter % 2 == 1)
            {
                printf("%d ", dpNum++);
            }
            else
            {
                printf("@ ");
            }
        }
        if (counter % 2 == 1)
            dpHolding++;
        printf("\n");
    }
}

void primeNumberRandom()
{
    printf("\n-----------------------\n\n");

    int count, newNum, inputCheck;
    printf("--Enter any alphabetic value to stop--\n");

    for (;;)
    {
        printf("\n\nEnter the number : ");
        inputCheck = scanf("%d", &newNum);

        if (inputCheck == 0)
        {
            break;
        }

        if (newNum > 0)
        {
            // Check whether the number is prime
            inputCheck = 0;
            for (count = 1; count <= newNum; count++)
            {
                if (newNum % count == 0)
                {
                    inputCheck++;
                }
            }
            if (inputCheck > 2)
            {
                printf("%d is a not prime number", newNum);
            }
            else
            {
                printf("%d is a prime number", newNum);
            }
        }
        else
        {
            printf("Given input is not valid.. please try again...");
        }
    }

    printf("\n\n-----------------------\n");
}

void primeNumberRange()
{
    printf("\n-----------------------\n\n");

    int count, inner_count, newNum, primeCounter, range;
    printf("Enter range : ");
    scanf("%d", &range);
    for (count = 1; count <= range; count++)
    {
        printf("\n\nEnter the number : ");
        scanf("%d", &newNum);

        if (newNum > 0)
        {
            // Check whether the number is prime
            primeCounter = 0;
            for (inner_count = 1; inner_count <= newNum; inner_count++)
            {
                if (newNum % inner_count == 0)
                {
                    primeCounter++;
                }
            }
            if (primeCounter > 2)
            {
                printf("%d is a not prime number", newNum);
            }
            else
            {
                printf("%d is a prime number", newNum);
            }
        }
        else
        {
            printf("Given input is not valid.. please try again...");
            count--;
        }
    }

    printf("\n\n-----------------------\n");
}

void summationPrimeCheck()
{
    printf("\n-----------------------\n\n");

    int newNum_count, inputCheck_pc, sum = 0;
    printf("--Enter any alphabetic value to stop--\n");
    for (;;)
    {
        printf("\nEnter the number : ");
        inputCheck_pc = scanf("%d", &newNum_count);

        if (inputCheck_pc == 0)
        {
            break;
        }
        sum += newNum_count;
    }
    printf("\n");
    if (sum > 0)
    {
        // Check whether the number is prime
        inputCheck_pc = 0;
        for (newNum_count = 1; newNum_count <= sum; newNum_count++)
        {
            if (sum % newNum_count == 0)
            {
                inputCheck_pc++;
            }
        }
        if (inputCheck_pc > 2)
        {
            printf("Sum = %d, is a not prime number", sum);
        }
        else
        {
            printf("Sum = %d, is a prime number", sum);
        }
    }
    else
    {
        printf("\nThe Summation is not valid..");
    }

    printf("\n\n-----------------------\n");
}

int primeChecker(int newNum)
{

    int primeCounter, count;
    primeCounter = 0;
    for (count = 1; count <= newNum; count++)
    {
        if (newNum % count == 0)
        {
            primeCounter++;
        }
    }
    if (primeCounter > 2)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void whosNextPrime()
{
    printf("\n-----------------------\n\n");

    int initialValue, count, primeCounter;

    printf("Enter any number : ");
    scanf("%d", &initialValue);

    if (initialValue > 0)
    {
        initialValue++;
        for (;; initialValue++)
        {
            primeCounter = 0;
            for (count = 1; count <= initialValue; count++)
            {
                if (initialValue % count == 0)
                {
                    primeCounter++;
                }
            }
            if (primeCounter <= 2 && primeCounter >= 1)
            {
                printf("The very next prime number is %d", initialValue);
                break;
            }
        }
    }
    else
    {
        printf("Given input is Invalid as a prime number");
    }

    printf("\n\n-----------------------\n");
}

void staticRangePalindrome()
{
    int userInput;
    printf("\nPalindrome Number with static range \n\n");

    for (int upCounter = 1; upCounter <= 200; upCounter++)
    {
        userInput = upCounter;
        int counter = userInput;
        int pdOut = 0;
        for (; counter != 0; counter /= 10)
        {
            pdOut *= 10;
            pdOut += counter % 10;
        }

        if (pdOut == userInput)
        {
            printf("%d ", userInput);
        }
    }
    printf("\n\n");
}

void dynamicRangePalindrome()
{
    int range;
    printf("\nEnter the Number of Range : ");
    scanf("%d", &range);

    printf("Palindrome Numbers between %d and %d are : \n", 1, range);

    for (int counter = 1; counter <= range; counter++)
    {
        int pdIn = counter;
        int pdCtrl = pdIn;
        int pdOut = 0;

        for (; pdCtrl != 0; pdCtrl /= 10)
        {
            pdOut = (pdOut * 10) + (pdCtrl % 10);
        }

        if (pdIn == pdOut)
        {
            printf("%d\n", pdIn);
        }
    }

    printf("\n\n");
}

void infiniteRangePalindrome()
{
    printf("\nEnter any character(x) to end the palindrome process : \n\n");

    for (;;)
    {
        int pdIn;
        printf("Enter any number : ");
        int inCheck = scanf("%d", &pdIn);
        if (inCheck != 0)
        {
            int pdCtrl = pdIn,
                pdOut = 0;

            for (; pdCtrl != 0; pdCtrl /= 10)
            {
                pdOut = (pdOut * 10) + (pdCtrl % 10);
            }

            if (pdIn == pdOut)
            {
                printf("%d is a palindrome number\n", pdIn);
            }
            else
            {
                printf("%d is a not palindrome number\n", pdIn);
            }
        }
        else
        {
            printf("\nProgram End !");
            break;
        }
        printf("\n");
    }

    printf("\n\n");
}

int armStrong(int armIn)
{
    int armLen = 0,
        armOut = 0;
    for (int count = armIn; count != 0; count /= 10)
    {
        armLen++;
    }
    for (int count = armIn; count != 0; count /= 10)
    {
        int item = 1;
        for (int innerCounter = 1; innerCounter <= armLen; innerCounter++)
        {
            item *= count % 10;
        }
        armOut += item;
    }

    if (armIn == armOut)
        return 1;
    else
        return 0;
}

void staticArmstrong()
{

    for (int counter = 1; counter <= 1000; counter++)
    {
        int armIn = counter,
            armLen = 0,
            armOut = 0;

        for (int count = armIn; count != 0; count /= 10)
        {
            armLen++;
        }

        for (int count = armIn; count != 0; count /= 10)
        {
            int item = 1;
            for (int innerCounter = 1; innerCounter <= armLen; innerCounter++)
            {
                item *= count % 10;
            }
            armOut += item;
        }

        if (armIn == armOut)
            printf("%d ", armIn);
    }
    printf("\n\n");
}

void armStrongRange()
{
    int range;
    printf("\nEnter the range for armstrong number : ");
    scanf("%d", &range);

    for (int counter = 1; counter <= range; counter++)
    {
        int armIn = counter,
            armLen = 0,
            armOut = 0;

        for (int inCounter = armIn; inCounter != 0; inCounter /= 10)
        {
            armLen++;
        }

        for (int inCounter = armIn; inCounter != 0; inCounter /= 10)
        {
            int item = 1;
            for (int innCounter = 1; innCounter <= armLen; innCounter++)
            {
                item *= inCounter % 10;
            }
            armOut += item;
        }

        if (armIn == armOut)
            printf("%d ", armIn);
    }
}

void strongNumber()
{
    int stIn, supIn, stSum = 0;

    printf("Enter the number : ");
    scanf("%d", &stIn);
    supIn = stIn;
    for (; stIn != 0; stIn /= 10)
    {
        int exVal = stIn % 10,
            factVal = 1;

        for (int count = exVal; count >= 1; count--)
        {
            factVal *= count;
        }

        stSum += factVal;

        printf("\n");
    }

    if (supIn == stSum)
    {
        printf("Its a strong Number\n");
    }
    else
    {
        printf("Its not a strong Number\n");
    }
}

void infiniteStrongNumber()
{

    printf("\nEnter any character(x) to exit the program ..\n");

    for (;;)
    {
        int stIn, stOut = 0;
        printf("\nEnter the number : ");
        int chkInp = scanf("%d", &stIn);

        if (chkInp == 1)
        {
            int supIn = stIn;
            for (; supIn != 0; supIn /= 10)
            {
                int wkItm = supIn % 10,
                    factNo = 1;
                for (int ftCtrl = 1; ftCtrl <= wkItm; ftCtrl++)
                {
                    factNo *= ftCtrl;
                }
                stOut += factNo;
            }

            stIn == stOut ? printf("Strong Number\n") : printf("Not an strong number\n");
        }
        else
        {
            printf("\nProgram End ..\n\n");
            break;
        }
    }
}

void rangeStrong()
{

    int range;
In1:
    printf("Enter the range : ");
    scanf("%d", &range);

    if (range > 10)
    {
        for (int count = 10; count <= range; count++)
        {
            int stIn = count,
                stOut = 0,
                supIn = stIn;

            for (; supIn != 0; supIn /= 10)
            {
                int numItm = supIn % 10,
                    factNum = 1;

                for (int inCount = numItm; inCount <= 1; inCount++)
                {
                    factNum *= inCount;
                }
                stOut += factNum;
            }

            stIn == stOut ? printf("%d ", stIn) : stIn;
        }
    }
    else
    {
        printf("Enter a valid range (greater than 10)\n\n");
        goto In1;
    }
}

void ABCDIncrementPattern()
{
    for (int counter = 1; counter <= 4; counter++)
    {
        printf("%c ", 64 + counter);
        for (int inCounter = 1; inCounter <= counter; inCounter++)
        {
            printf("%d ", inCounter);
        }
        printf("\n");
    }
}


void R_Multiplication()
{
    int counter,output = 1;
    /* Static Multiplication using For loop */
    printf("\n--------------Static---------------\n");
    for(counter=1;counter<=8;counter++)
    {
        output = output * counter;
    }
    printf("The Static Multiplication is : %d", output);
    /* Dynamic Multiplication using for Loop */
    printf("\n\n--------------Dynamic--------------\n");
    int _dynamic;
    output = 1;
    printf("Enter the range : ");
    scanf("%d", &_dynamic);
    for(counter=_dynamic-_dynamic+1;counter<=_dynamic;counter++)
    {
        output = output * counter;
    }
    printf("The Dynamic Multiplication is : %d", output);
    printf("\n\n");
}
void R_Subtration()
{
    int counter, output=5;
    /* Static Loop Subtration */
    printf("\n--------------Static---------------\n");
    for(counter=output;counter>=1;counter--)
    {
        output = output - counter;
    }
    printf("Static Subtration is : %d" , output);
    /* Dynamic Loop Subtration */
    printf("\n\n--------------Dynamic--------------\n");
    printf("Enter the range : ");
    scanf("%d", &output);
    for(counter=output;counter>=1;counter--)
    {
        output = output - counter;
    }
    printf("Dynamic Subtration is : %d" , output);
    printf("\n\n");
}

void d_program()
{
    int a=5;
    for(; a >= 1; a++)
    {
        int b = 4+a;
        printf("Inside Scope : %d", b);
    }
    printf("\nOutside Scope : %d", b);
}