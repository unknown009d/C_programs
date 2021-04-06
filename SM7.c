#include "drb.h"

void wait()
{
    int a[20],
        b[20],
        a_r = 0,
        b_r = 0,
        inpIndex = 0;

    a_r = input("Enter the first array range : ");

    printf("Enter the first Array : \n");
    for (int i = 0; i < a_r; i++)
    {
        scanf("%d", &a[i]);
    }

    b_r = input("Enter the second array range : ");

    printf("Enter the Second Array : \n");
    for (int i = 0; i < b_r; i++)
    {
        scanf("%d", &b[i]);
    }

    printf("\nThe first array is : \n");
    for (int i = 0; i < a_r; i++)
    {
        printf("%d", a[i]);
    }

    printf("\n\nThe Second array is : \n");
    for (int i = 0; i < b_r; i++)
    {
        printf("%d", b[i]);
    }

    inpIndex = input("\n\nEnter the index number : ");

    for (int i = inpIndex; i <= b_r; i++)
    {
        // a[i+b_r] = a[i];
        a[i] = 0;
    }

    a_r += b_r;
    printf("\nElements with spaces : ");
    for (int i = 0; i < a_r; i++)
    {
        printf("%d ", a[i]);
    }
}

void mergingArray()
{
    int ar[20],
        arLen = 0,
        i = 0, j = 0,
        br[20],
        brLen = 0,
        ext[20],
        extLen = 0;

    /* First array */
    arLen = input("Enter the first array elements range : ");
    for (i = 0; i < arLen; i++)
        scanf("%d", &ar[i]);
    printf("\nThe first array is : \n[ ");
    for (i = 0; i < arLen; i++)
        printf("%d ", ar[i]);
    printf("]\n");

    /* Second array */
    brLen = input("\nEnter the second array elements range : ");
    for (i = 0; i < brLen; i++)
        scanf("%d", &br[i]);
    printf("\nThe second array is : \n[ ");
    for (i = 0; i < brLen; i++)
        printf("%d ", br[i]);
    printf("]\n");

    /* Third Array */

    extLen = arLen + brLen;
    for (i = 0; i < arLen; i++)
        ext[i] = ar[i];
    j = arLen;
    for (i = 0; i < brLen; i++)
        ext[j++] = br[i];
    printf("\nThe Third array is : \n[ ");
    for (i = 0; i < extLen; i++)
        printf("%d ", ext[i]);
    printf("]\n");
}

void frequencyChecker()
{
    int inpData[20], inpRange = 0, count = 0, st_inpData[20], stRange = 0;
    printf("Enter the element range : ");
    scanf("%d", &inpRange);
    /* Array Insertion (Input from User) */
    printf("\nEnter the array elements : \n");
    for (count = 0; count < inpRange; count++)
        scanf("%d", &inpData[count]);
    putchar(10);
    /* Cycle for traversing each elements */
    for (count = 0; count < inpRange; count++)
    {
        for (int i = 0; i < stRange; i++)
        {
            if (st_inpData[i] == inpData[count])
                goto L1;
        }
        int inpDataCounter = 1;
        for (int i = count + 1; i < inpRange; i++)
        {
            if (inpData[count] == inpData[i])
                inpDataCounter++;
        }
        printf("%d - %d\n", inpData[count], inpDataCounter);
        st_inpData[stRange] = inpData[count];
        stRange++;
    L1:
        putchar(0);
    }
}

void d_program()
{
    int inp1[20], inp2[20], rg1 = 0, rg2 = 0, i, j, indNum;

    printf("Enter the range : ");
    scanf("%d", &rg1);
    printf("Enter the array elements : \n");
    for (i = 0; i < rg1; i++)
        scanf("%d", &inp1[i]);

    printf("Enter the range : ");
    scanf("%d", &rg2);
    printf("Enter the array elements : \n");
    for (i = 0; i < rg2; i++)
        scanf("%d", &inp2[i]);

    printf("\nEnter the index number to be inserted : ");
    scanf("%d", &indNum);

    putchar(10);
    for (i = indNum; i < rg1; i++)
    {
        inp1[i + rg2] = inp1[i];
        printf("inp1[%d + %d](%d) = %d\n", i, rg2, inp1[i + rg2], inp1[i]);
    }
    for (i = 0; i < rg2; i++)
        inp1[indNum + i] = inp2[i];

    rg1 += rg2;
    printf("\n------\n[ ");
    for (i = 0; i < rg1 + 2; i++)
        printf("%d ", inp1[i]);
    printf("]\n------\n");
}