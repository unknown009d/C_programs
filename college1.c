#include "drb.h"

void q1()
{
    int a[20], range, count = 0, small;

    printf("Enter the range : ");
    scanf("%d", &range);

    printf("\nEnter the array elements : \n");
    do
    {
        scanf("%d", &a[count]);
        count++;
    } while (count < range);

    small = a[0];

    count = 0;
    do
    {
        if (small > a[count])
            small = a[count];
        count++;
    } while (count < range);

    printf("\n\nThe Smallest Number in this array is %d", small);
}

void q2()
{
    int a[10][10], range, count, inCount, largeNo = 0;

    printf("Enter the range : ");
    scanf("%d", &range);

    printf("Enter the array Numbers : \n");
    count = 0;
    do
    {
        inCount = 0;
        do
        {
            scanf("%d", &a[count][inCount]);
            inCount++;
        } while (inCount < range);

        count++;
    } while (count < range);

    count = 0;
    do
    {
        inCount = 0;
        do
        {
            if (largeNo < a[count][inCount])
            {
                largeNo = a[count][inCount];
            }
            inCount++;
        } while (inCount < range);

        count++;
    } while (count < range);

    printf("\n%d is greater", largeNo);
}

void q3()
{
    int a[20], range, count = 0, large, sLarge;

    printf("Enter the range : ");
    scanf("%d", &range);

    printf("\nEnter the array elements : \n");
    do
    {
        scanf("%d", &a[count]);
        count++;
    } while (count < range);

    count = 0;
    large = 0;
    do
    {
        if (large < a[count])
            large = a[count];
        count++;
    } while (count < range);

    count = 0;
    sLarge = 0;
    do
    {
        if (a[count] != large)
        {
            if (sLarge < a[count])
                sLarge = a[count];
        }
        count++;
    } while (count < range);

    printf("\n\nThe Second Largest Number in this array is %d", sLarge);
}

void q4()
{
    int a[10][10], range, c, cp, smNum, smNum2;

    printf("Enter the range : ");
    scanf("%d", &range);

    printf("\nEnter the elements of the 2D array : \n");
    c = 0;
    do
    {
        cp = 0;
        do
        {
            printf("\na[%d][%d] : ", c, cp);
            scanf("%d", &a[c][cp]);
            cp++;
        } while (cp < range);
        c++;
    } while (c < range);

    smNum = a[0][0];
    c = 0;
    do
    {
        cp = 0;
        do
        {
            if (smNum > a[c][cp])
                smNum = a[c][cp];
            cp++;
        } while (cp < range);
        c++;
    } while (c < range);

    c = 0;
    do
    {
        cp = 0;
        do
        {
            if (a[c][cp] != smNum)
                smNum2 = a[c][cp];
            goto endL;
            cp++;
        } while (cp < range);
        c++;
    } while (c < range);

endL:
    c = 0;
    do
    {
        cp = 0;
        do
        {
            if (a[c][cp] != smNum)
            {
                if (smNum2 > a[c][cp])
                    smNum2 = a[c][cp];
            }
            cp++;
        } while (cp < range);
        c++;
    } while (c < range);

    printf("\nSecond Smallest Number is : %d", smNum2);
}

/* ArmStrong */

int findLenth(int num)
{
    if (num == 0) return num;
    return 1 + findLenth(num /= 10);
}

void d_program()
{
      debug(findLenth(12));
}
