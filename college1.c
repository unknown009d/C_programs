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

    count = 0;
    small = 0;
    do
    {
        if (small < a[count])
            small = a[count];
        count++;
    } while (count < range);

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

void d_program()
{
    q3();
}