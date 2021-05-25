#include "drb.h"

typedef struct singleLinkListNode
{
    int data;
    struct singleLinkListNode *link;
} snode;

typedef struct doublyLinkListNode
{
    int data;
    struct doublyLinkListNode *prev_link;
    struct doublyLinkListNode *next_link;
} dnode;

int continueProgramPrompt(char message[])
{
    int choice = 0;
    printf("\n\n0. Exit\n1. To Continue (%s)\n-> ", message);
    scanf("%d", &choice);
    if (choice)
        system("clear");
    return choice;
}

/* ---- For Single Linked List ---- */
int checkExistence(snode *current, int value)
{
    if (current == NULL)
        return 0;
    if (current->data == value)
        return 1;
    return checkExistence(current->link, value);
}
void itterateUntilEnd(snode *current, snode *newData)
{
    if (current->link == NULL)
        current->link = newData;
    else
        itterateUntilEnd(current->link, newData);
}
snode *createNode(snode *current)
{
    int _data;
rtRoll:
    printf("\nEnter the Number : ");
    scanf("%d", &_data);
    if (_data > 0 && checkExistence(current, _data))
    {
        printf("Invalid/Existence Roll Number. Try Again\n");
        goto rtRoll;
    }
    if (_data == -1)
        return current;
    snode *new;
    new = (snode *)malloc(sizeof(snode));
    new->data = _data;
    new->link = NULL;
    if (current == NULL)
        current = new;
    else
        itterateUntilEnd(current, new);
    return createNode(current);
}
void showNode(snode *current)
{
    printf("%d", current->data);
    if (current->link != NULL)
    {
        printf(" > ");
        showNode(current->link);
    }
}
int countNodes(snode *current)
{
    if (current->link == NULL)
        return 1;
    return 1 + countNodes(current->link);
}
void selectionSort(snode *current, int choice)
{
    for (snode *i = current; i->link != NULL; i = i->link)
    {
        for (snode *j = i->link; j != NULL; j = j->link)
        {
            int compare = choice == 2 ? i->data < j->data : i->data > j->data;
            if (compare)
            {
                int _data = i->data;
                i->data = j->data;
                j->data = _data;
            }
        }
    }
}
/* ---- End of Single Linked List ---- */

/* ---- For Doubly Linked List ---- */
void itterateUntilEndDOUBLY(dnode *current, dnode *newData)
{
    if (current->next_link == NULL)
    {
        current->next_link = newData;
        newData->prev_link = current->next_link;
    }
    else
        itterateUntilEndDOUBLY(current->next_link, newData);
}
int checkExistenceDOUBLY(dnode *current, int value)
{
    if (current == NULL)
        return 0;
    if (current->data == value)
        return 1;
    return checkExistenceDOUBLY(current->next_link, value);
}
dnode *createNodeDOUBLY(dnode *current)
{
    int _data;
rtyID:
    printf("\nEnter the ID : ");
    scanf("%d", &_data);
    if (_data > 0 && checkExistenceDOUBLY(current, _data))
    {
        printf("Invalid/Existence ID Number. Try Again\n");
        goto rtyID;
    }
    if (_data == -1)
        return current;
    dnode *new;
    new = (dnode *)malloc(sizeof(dnode));
    new->data = _data;
    new->prev_link = NULL;
    new->next_link = NULL;
    if (current == NULL)
        current = new;
    else
        itterateUntilEndDOUBLY(current, new);
    return createNodeDOUBLY(current);
}
void showNodeDOUBLY(dnode *current)
{
    printf("%d", current->data);
    if (current->next_link != NULL)
    {
        printf(" <> ");
        showNodeDOUBLY(current->next_link);
    }
    else
        printf("\n");
    printf("%d", current->data);
    if (current->prev_link != NULL)
        printf(" <> ");
}
dnode *findLargestNodeDOUBLY(dnode *current)
{
    dnode *large;
    if (current->next_link == NULL)
        return current;
    large = findLargestNodeDOUBLY(current->next_link);
    if (large->data < current->data)
        large = current;
    return large;
}
/* ---- End of Doubly Linked List ---- */

dnode *convertSingleToDoubly(snode *current, dnode *newNode)
{
    dnode *_tmp = NULL;
    _tmp = (dnode *)malloc(sizeof(dnode));
    _tmp->prev_link = NULL;
    _tmp->data = current->data;
    _tmp->next_link = NULL;
    if (newNode == NULL)
        newNode = _tmp;
    else
        itterateUntilEndDOUBLY(newNode, _tmp);
    if (current->link != NULL)
        convertSingleToDoubly(current->link, newNode);
    return newNode;
}

void d_program()
{
    system("clear");
    snode *rollno = NULL;
    printf("\n1. Make a Single Linked List\
            \n-----------------------------\n");
    printf("\n--- ( -1 to stop ) ---\n");
    rollno = createNode(NULL);
    printf("\n\nNumber of Items in the List : %d", countNodes(rollno));
    printf("\n\nThe List is : \n");
    showNode(rollno);

    if (!continueProgramPrompt("Maximum Value in Doubly Linked List"))
        return;

    printf("\n2. Maximum Value in Doubly Linked List\
            \n-----------------------------------\n\n");
    dnode *id = NULL;
    printf("\n--- ( -1 to stop ) ---\n");
    id = createNodeDOUBLY(NULL);
    printf("\nThe Doubly List is : \n");
    showNodeDOUBLY(id);
    printf("\n\nThe Largest Number is : %d", findLargestNodeDOUBLY(id)->data);

    if (!continueProgramPrompt("Sort a Single Linked List"))
        return;

    int sortChoice = 1;
    rollno = NULL;
    printf("\n3. Sort a Single Linked List\
            \n-----------------------------\n");
    printf("\n--- ( -1 to stop ) ---\n");
    rollno = createNode(NULL);
    printf("\n\nThe List is : \n");
    showNode(rollno);
    printf("\n\nEnter the type of Sorting : \n");
    printf("1. Ascending\n2. Descending\n\n-> ");
    scanf("%d", &sortChoice);
    selectionSort(rollno, sortChoice);
    printf("\nThe List After Sorting is : \n");
    showNode(rollno);

    if (!continueProgramPrompt("Convert Single to Doubly LinkedList"))
        return;

    rollno = NULL;
    printf("\n4. Convert Single Linked List to Doubly Linked List\
            \n----------------------------------------------------\n");
    printf("\n--- ( -1 to stop ) ---\n");
    rollno = createNode(NULL);
    printf("\n\nThe Single LinkedList is : \n");
    showNode(rollno);
    id = NULL;
    id = convertSingleToDoubly(rollno, NULL);
    printf("\n\nThe Single Converted into Doubly LinkedList is : \n");
    showNodeDOUBLY(id);
}