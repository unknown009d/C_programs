#include "drb.h"

void showQueue(int array[], int count)
{
    printf("\nThe queue is : ");
    for(int i = 0; i < count; i++)
        printf("%d", array[i]);
}

void addQueue(int array[], int *count, int data)
{
    array[*count] = data;
    *count++;
}


void d_program()
{
    int q_data[20], q_ct = 0;
    addQueue(q_data, &q_ct, 5);
    //addQueue(q_data, &q_ct, 10);
    //addQueue(q_data, &q_ct, 15);
    printf("\n");
    showQueue(q_data, q_ct);
}