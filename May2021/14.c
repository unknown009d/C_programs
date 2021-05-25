/* Linked List - May 14th 2021 (Drubajyoti Debnath) */

#include "drb.h"
#define MAX_STR 50

int continueProgramPrompt(char message[])
{
    int choice = 0;
    printf("\n\n0. Exit\n1. To Continue (%s)\n-> ", message);
    scanf("%d", &choice);
    if (choice)
        system("clear");
    return choice;
}

typedef struct rawnode
{
    int id;
    struct rawnode *link;
} node;

int checkUntilRoll(node *HEAD, int keyElement)
{
    if (HEAD->id == keyElement)
        return 1;
    if (HEAD->link == NULL)
        return HEAD->id == keyElement ? 1 : 0;
    return checkUntilRoll(HEAD->link, keyElement);
}

int countNodes(node *HEAD)
{
    if (HEAD->link == NULL)
        return 1;
    return 1 + countNodes(HEAD->link);
}
void showNode(node *HEAD)
{
    printf("%d", HEAD->id);
    HEAD->link != NULL ? printf("->") : 0;
    if (HEAD->link != NULL)
        showNode(HEAD->link);
}

void itterateAddNode(node *HEAD, node *current)
{
    if (HEAD->link != NULL)
        itterateAddNode(HEAD->link, current);
    else
        HEAD->link = current;
}

node *newNode(node *HEAD)
{
    node *temp = NULL;
    char checkInp;
    int inpRet = 0, inpVal = 0;
L1:
    printf("-> ");
    inpRet = scanf("%d", &inpVal);
    scanf("%c", &checkInp);
    if (!inpRet)
        return HEAD;
    temp = (node *)malloc(sizeof(node));
    if (HEAD != NULL && checkUntilRoll(HEAD, inpVal) != 0)
    {
        printf("Roll Number already Exist. Try Again\n");
        goto L1;
    }
    temp->id = inpVal;
    temp->link = NULL;
    if (HEAD == NULL)
        HEAD = temp;
    else
        itterateAddNode(HEAD, temp);
    return newNode(HEAD);
}

node *duplicateNodes(node *from, node *to)
{
    node *temp = NULL;
    temp = (node *)malloc(sizeof(node));
    temp->id = from->id;
    temp->link = NULL;
    if (to == NULL)
        to = temp;
    else
        itterateAddNode(to, temp);
    if (from->link == NULL)
        return to;
    return duplicateNodes(from->link, to);
}

node *findNodeWithNumber(node *data, int length)
{
    if (length == 0)
        return data;
    return findNodeWithNumber(data->link, --length);
}

node *duplicateNodesLength(node *from, node *to, int length)
{
    node *temp = NULL;
    temp = (node *)malloc(sizeof(node));
    temp->id = from->id;
    temp->link = NULL;
    if (to == NULL)
        to = temp;
    else
        itterateAddNode(to, temp);
    if (length == 1)
        return to;
    return duplicateNodesLength(from->link, to, --length);
}

void existNode(node *HEAD, node **node1, node **node2)
{
    int HEADLength[2] = {
        countNodes(HEAD) - (countNodes(HEAD) / 2),
        countNodes(HEAD) / 2};

    *node1 = duplicateNodesLength(HEAD, *node1, HEADLength[0]);
    HEAD = findNodeWithNumber(HEAD, countNodes(*node1));
    *node2 = duplicateNodesLength(HEAD, *node2, HEADLength[1]);
}

void d_program()
{
    system("clear");
    node *a = NULL;
    int choice = 0;
L2:
    printf("\n1. Make a Single Linked List\
            \n-----------------------------\n\n");
    printf("Enter the Numbers\n( x to stop ) :\n\n");
    a = newNode(NULL);
    printf("\n\n(A) List is :\n");
    showNode(a);

    if (!continueProgramPrompt("Make another Linked List"))
        return;

    printf("\n2. Make Another Single Linked List\
            \n-----------------------------------\n\n");
    node *b = NULL;
    printf("Enter the Numbers\n( x to stop ) :\n\n");
    b = newNode(NULL);
    printf("\n\n(A) List is :\n");
    showNode(a);
    printf("\n\n(B) List is :\n");
    showNode(b);

    if (!continueProgramPrompt("Make Duplicate of (A)"))
        return;

    printf("\n3. Duplicate of (A) Single Linked List\
            \n---------------------------------------\n\n");
    node *duplicateA = NULL;
    duplicateA = duplicateNodes(a, duplicateA);
    printf("Duplicate List (A) :\n");
    showNode(duplicateA);

    if (!continueProgramPrompt("Break Linked List"))
        return;

    printf("\n4. Break the Duplicate of (A)\
            \n------------------------------\n\n");
    node *dup1 = NULL, *dup2 = NULL;
    if (countNodes(duplicateA) < 2)
    {
        printf("More than 1 Data is needed to Break them in two Parts ..\n\n");
        goto L2;
    }
    printf("After breaking the duplicate into two parts : \n");
    existNode(duplicateA, &dup1, &dup2);
    printf("\n\nList is : \n\n");
    showNode(dup1);
    printf("\n\n----\n\n");
    showNode(dup2);

    if (!continueProgramPrompt("Merge Linked List"))
        return;

    printf("\n5. Merge Two Linked List \
            \n------------------------------\n\n");

    node *m1, *m2, *m3;

    printf("Enter the Numbers\n( x to stop ) :\n\n");
    a = newNode(NULL);
    printf("\n\n(A) List is :\n");
    showNode(a);
}
