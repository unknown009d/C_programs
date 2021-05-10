#include "drb.h"
#define MAX 69
/* Linked List (May 4th 2021) */

typedef struct rawnode
{
    int id;
    struct rawnode *link;
} node;

void simple()
{
    node a, b, c;

    a.id = 5;
    a.link = &b;

    a.link->id = 6;
    a.link->link = &c;

    a.link->link->id = 5;
    a.link->link->link = NULL;

    printf("a : \n%d\t%p", a.id, a.link);
    printf("\nb : \n%d\t%p", b.id, b.link);
    printf("\nc : \n%d\t%p", c.id, c.link);
}

node *prevNode(node *data, int x)
{
    if (data->link->id != x)
        data = prevNode(data->link, x);
    return data;
}

int checkExsistence(node *data, int element, int firstNodeID)
{
    // int retVal = 0;
    // node *previous;
    // previous = prevNode(data, element);
    // previous = prevNode(data, element);
    // if (previous->id == firstNodeID)
    // {
    //     checkExsistence(data, previous->id, firstNodeID);
    // }
    printf("\n--exist : %d\n", data->id);
    return 0;
    // while (previous->id != firstNodeID)
    // {
    //     if (previous->id == element)
    //     {
    //         retVal = 1;
    //         break;
    //     }
    //     previous = prevNode(data, previous->id);
    // }
    // return retVal;
}

void addNode(node *data, node *st_data)
{
    int retChk = 0;
    node *_temp;
L1:
    printf("\nEnter Number (-1 to stop) : ");
    scanf("%d", &data->id);
    retChk = checkExsistence(st_data, data->id, st_data->id);
    // printf("\nEX: %d\n", retChk);

    if (retChk)
        goto L1;

    if (data->id == -1)
    {
        _temp = prevNode(st_data, -1);
        free(data);
        _temp->link = NULL;
    }
    else
    {
        data->link = (node *)malloc(sizeof(node));
        addNode(data->link, st_data);
    }
}

void showNode(node *data)
{
    if (data->link != NULL)
    {
        printf("%d ", data->id);
        showNode(data->link);
    }
    else
    {
        printf("%d", data->id);
    }
}

void twoLinkedList()
{
    node *a, *b;
    a = (node *)malloc(sizeof(node));
    addNode(a, a);
    // b = (node *)malloc(sizeof(node));
    // addNode(b, b);
    printf("\nA : ");
    showNode(a);
    // printf("\n\nB : ");
    // showNode(b);
}

void reverseList(node *from, node *to)
{
}

void reverseLinkedList()
{
    node *a;
    printf("Enter the List : \n");
    a = (node *)malloc(sizeof(node));
    addNode(a, a);
    printf("\nEntered List is : \n[ ");
    showNode(a);
    printf(" ]");
    // b = (node *)malloc(sizeof(node));
    // reverseList(b, a);
}

void d_program()
{
    twoLinkedList();
}