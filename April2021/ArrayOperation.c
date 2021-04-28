#include "drb.h"

/* Array Operations */

void addList(int itemArr[], int *arCount)
{
    printf("\nEnter the numbers (x to stop) :\n");
    for (;; (*arCount)++)
    {
        int inpRet = scanf("%d", &itemArr[*arCount]);
        if (!inpRet)
            break;
    }
}

void showList(int itemArr[], int arCount)
{
    printf("\n[");
    int i = 0;
    while (i < arCount)
    {
        printf("%d", itemArr[i++]);
        if (i < arCount)
            printf(",");
    }
    printf("]");
}

int searchItem(int arr[], int arCount)
{
    int retVal = 0;
    int data = input("\nEnter the value to search : ");
    for (int i = 0; i < arCount; i++)
    {
        if (arr[i] == data)
        {
            printf("\n%d is found in position %d.\n", data, i);
            retVal = 1;
            break;
        }
    }
    !retVal ? printf("\nElement is not availabe in this list.") : printf("%c", 0);
}

void appendItem(int arr[], int *arCount)
{
    printf("\nEnter an Number to append : ");
    scanf("%d", &arr[(*arCount)++]);
}

void insertItem(int arr[], int *arCount)
{
    int pos;
    printf("\nEnter the index (upto %d) to insert the data : ", (*arCount) - 1);
    scanf("%d", &pos);
    (*arCount)++;
    for (int i = (*arCount) - 1; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    printf("\nEnter the data : ");
    scanf("%d", &arr[pos]);
}

void removeItem(int arr[], int *arCount)
{
    arr[(*arCount)--] = 0;
}

void deleteItem(int arr[], int *arCount)
{
    int pos;
    printf("\nEnter the index number (upto %d) to delete : ", (*arCount) - 1);
    scanf("%d", &pos);
    for (int i = pos + 1; i < *arCount; i++)
    {
        arr[i - 1] = arr[i];
    }
    (*arCount)--;
}

void mergeLists(int arr1[], int *ar1ct, int arr2[], int *ar2ct)
{
    for (int i = 0; i < *ar2ct; i++)
        arr1[(*ar1ct)++] = arr2[i];
}

/* Sorting */
void selectionSort(int arr[], int *arCount)
{
    for (int ctn = 0; ctn < (*arCount) - 1; ctn++)
    {
        for (int inCtn = ctn + 1; inCtn < *arCount; inCtn++)
        {
            if (arr[ctn] > arr[inCtn])
            {
                d_swapInt(&arr[ctn], &arr[inCtn]);
            }
        }
    }
}

void d_programs()
{
    int arr[50] = {4, 6, 2, 8, 10, 23, 63, 45}, arCount = 8,
        arr2[50] = {25, 45, 23, 12, 54}, arCount2 = 5;

    printf("The First Array is : \n");
    showList(arr, arCount);
    printf("\n\nThe Second Array is : \n");
    showList(arr2, arCount2);

    mergeLists(arr, &arCount, arr2, &arCount2);

    printf("\n\n=======AFTER======\n");

    printf("The First Array is : \n");
    showList(arr, arCount);
    printf("\n\nThe Second Array is : \n");
    showList(arr2, arCount2);
}

void d_program()
{
    
}