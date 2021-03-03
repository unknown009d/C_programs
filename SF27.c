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

void selectionSortAL(int numbers[], int memCount)
{
    for (int i = 0; i < memCount - 1; i++)
    {
        for (int j = i + 1; j < memCount; j++)
        {
            if (numbers[i] > numbers[j])
            {
                int _temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = _temp;
            }
        }
    }
}

void bubbleSortAL(int numbers[], int memCount)
{
    for (int i = 0; i < memCount - 1; i++)
    {
        for (int j = 0; j < memCount - 1 - i; j++)
        {
            if (numbers[j] > numbers[j + 1])
                d_swapInt(&numbers[j], &numbers[j + 1]);
        }
    }
}

void insertionSortAL(int numbers[], int memCount)
{
    for (int i = 0; i < memCount - 1; i++)
    {
        if (numbers[i] > numbers[i + 1])
        {
            d_swapInt(&numbers[i], &numbers[i + 1]);
            for (int j = i; j > 0; j--)
            {
                if (numbers[j] < numbers[j - 1])
                {
                    d_swapInt(&numbers[j], &numbers[j - 1]);
                }
            }
        }
    }
}

void sortingMain()
{
    int numbers[20], memCount;

    printf("Enter the Number of Elements : \nPress (x) to stop... \n");
    for (memCount = 0; memCount < 20; memCount++)
    {
        if (memCount == 19)
        {
            printf("\nMemory Exhausted\nProgram End !");
            return;
        }
        printf("\nMemory [%d] : ", memCount + 1);
        int inpChk = scanf("%d", &numbers[memCount]);
        if (inpChk == 0)
            break;
    }
    printf("\nMemory of array numbers are (BEF) : \n");
    listArray(numbers, memCount);

    printf("\nArray sorted : ");
    listArray(numbers, memCount);
}

